#include<bits/stdc++.h>
using namespace std;

//全局变量声明
int chess[402][402];
int chess_[402][402];
int n,m,x,y;//nxm的棋盘，马的原始位置(x,y)
//函数声明：
bool check_in_chess(int dx,int dy);
void BFS(int dx,int dy);
struct node
{
    int x;int y;
};
//二维数组，代表着左，上，右，下走
int dir[4][2]={
    {-2,1},//左
    {-1,2},
    {2,1},
    {1,-2}
};
int main()
{
    cin>>n>>m>>x>>y;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            chess[i][k]=-1;
        } 
    }
    chess[x][y]=0;
    BFS(x,y);
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            cout<<chess[i][k]<<" ";
        } 
        cout<<endl;
    }
    int aaa;
    cin>>aaa;
}
void BFS(int dx,int dy)
{
    queue<node> q;
    node start,next;
    start.x=dx;start.y=dy;
    q.push(start);
    int num=0;
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        num++;
        for(int i=0;i<8;i++)
        {
            next.x=start.x+dir[i];
            next.y=start.y+dir[i];
            if(check_in_chess(next.x,next.y)
            &&chess[next.x][next.y]==-1)
            {
                chess[next.x][next.y]=num;
                q.push(next);
            }
        }
    }
}
node 
bool check_in_chess(int dx,int dy)
{
    return dx<n&&dx>=1&&dy<m&&dy>=1;
}