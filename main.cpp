#include <iostream>
#include<cstdlib>
#include<cstdbool>
#define M 5
#define N 5
using namespace std;
bool bp[M][N];
bool bpMax(int u, bool visit[], int a[]) {
for (int v = 0; v < N; v++) {
if (bp[u][v] && !visit[v]) {
visit[v] = true;
if (a[v] < 0 || bpMax(a[v], visit,a)) {
a[v] = u;
return true;
}
}
}
return false;
}
int maxMatch() {
int a[N];
for(int i = 0; i<N; i++)
a[i] = -1;
int c = 0;
for (int u = 0; u < M; u++) {
bool visit[N];
for(int i = 0; i<N; i++)
visit[i] = false;
if (bpMax(u, visit, a))
c++;
}
return c;
}
int main() {
cout<<"Enter the matrix:\n";
int i,j;
int graph[M][N];
for(i=0;i<M;i++)
{
for(j=0;j<N;j++)
{
cin>>graph[i][j];
bp[i][j]=graph[i][j];
}
}
cout << "The processors can run a maximum of "<< maxMatch() <<" tasks at one time." << endl;
return 0;
}
