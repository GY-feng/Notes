#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
struct edge
{
    int from ,to;
    edge(int a,int b){from=a;to=b;}
};
int chu[MAXN],ru[MAXN];
bool visited[MAXN];
vector<edge> e[MAXN];
int path=0;
int n,m;//生物种类 n 和吃与被吃的关系数 m
void dfs(edge u);
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(edge(a,b));//a,b这之间的边存储到a的邻接表当中
        chu[a]++,ru[b]++;
    }
    dfs(edge(1,1));
    cout<<path<<endl;
    cin>>n;
}
void dfs(edge u)
{
    //visited[u.from]=true;
    if(chu[u.from]==0)//出度为0了
    {
        path++;
    }
    for (int i = 0; i < e[u.from].size(); i++)
    {
        edge v=e[u.from][i];
        dfs(v);
    }
    
}