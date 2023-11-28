//可以运行，但是运行效率竟然没有递推版本的快（超时了）
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[32][32] = {0};
int ctrl[32][32], n, m, hx, hy;
int d[9][2] = {{0, 0}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int total=0;
void DFS(int x,int y);
bool check(int x,int y);
int main()
{
    cin >> n >> m >> hx >> hy;
    for (int i = 0; i < 9; i++)
    {
        int tmpx = hx + d[i][0], tmpy = hy + d[i][1];
        if (tmpx >= 0 && tmpx <= n && tmpy >= 0 && tmpy <= m)
        {
            ctrl[tmpx][tmpy] = 1;//马的点设置成1
        }
    }
    if(hx==0&&hy==0)
    {
        cout<<0;
        return 0;
    }
    DFS(0,0);
    cout<<total;
    cin>>hx;
}
bool check(int x,int y)
{
    if(ctrl[x][y]==1)
        return false;
    if(x <0 && x > n &&y < 0 && y > m)
    {
        return false;//不合法哦
    }
    return true;
}
void DFS(int x,int y)
{
    if(x==n&&y==m)
    {
        total++;
        return ;
    }
    if(x+1<=n&&check(x+1,y))
    {
        DFS(x+1,y);
    }
    if(y+1<=m&&check(x,y+1))
    {
        DFS(x,y+1);
    }
}