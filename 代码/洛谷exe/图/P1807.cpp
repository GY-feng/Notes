#include<bits/stdc++.h>
using namespace std;
int n,m;//图的数量和边数
struct edge
{
    int from,to,w;
    edge(int a,int b,int c){from=a;to=b;w=c;}
};
vector<edge> e;
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        e.push_back((edge){x,y,z});
    }
}
void dfs(int u,int w)
{
    
}