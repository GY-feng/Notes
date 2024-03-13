#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int NUM = 100005;
int m, n;
struct edge
{
    int from;
    int to, maxn;
    edge(int a, int b)
    {
        from = a;
        to = b;
        maxn = a;
    }
};
vector<edge> e[NUM];
int mn = 0;
int vis[NUM];

void search(int u); // 采用dfs

int main()
{
    cin >> n >> m; // 点数和边数
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(edge(x, y));
    }
    for (int i = 1; i <= n; i++)
    {
        search(i);
        cout << mn << " ";
        mn = 0;
        memset(vis, 0, sizeof(vis));
    }
}

void search(int u) // 采用dfs
{
    mn = max(mn, u); // 先把自己设置成最大值先
    vis[u] = 1;      // 代表访问过了
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].to;
        if (!vis[v])
        {
            search(v);
        }
    }
}