//由于不明原因错误没做出来
#include <bits/stdc++.h>
using namespace std;
#define  MAX_N 100000
int m;
int deathtime[305][305] ;
int gotime[305][305];

struct Point
{
    int x,y;
};
queue<Point> q;
int wk[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
// 本质：对格子多了个使用时间的 限制，所以可以预先处理出每个格子最早被流星雨砸中的时间
// 那么在状态转移的时候，如果目标格子的到达时间已经比被破坏时间晚了，就不能被扩展了
void FireField(int x, int y, int t);
int main()
{
    memset(gotime,-1,sizeof(gotime));
    memset(deathtime,0x7f,sizeof(deathtime));
    cin >> m;
    int x1 = 0, y2 = 0, t2 = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> x1 >> y2 >> t2;
        //FireField(x1, y2, t2);
    }
    #define MIN(x,y,t)if(x>=0&&y>=0)deathtime[x][y]=min(deathtime[x][y],t)
    MIN(x1,y2,t2);
    for(int k=0;k<4;k++)
    {
        MIN(x1+wk[k][0],y2+wk[k][1],t2);
    }
    q.push((Point){0,0});
    gotime[0][0]=0;
    while (!q.empty())
    {
        Point point=q.front();
        q.pop();
        int px=point.x;int py=point.y;
        for (int k = 0; k < 4; k++)
        {
            int x=px+wk[k][0];int y=py+wk[k][1];
            if(x<0||y<0||gotime[x][y]!=-1||gotime[px][py]+1>=deathtime[x][y])//gotime:目标格子到达的最早时间
            //并且当目标格子最早到达时间已经比被破坏的时间晚的时候不更新
            {
                continue;
            }
             gotime[x][y]=gotime[px][py]+1;
            q.push((Point){x,y});
        }
        
    }
    int ANS=1000000;
    for (int i = 0; i <= 305; i++)
    {
        for (int k = 0; k <= 305; k++)
        {
            if(deathtime[i][k]!=0&&gotime[i][k]!=-1)
            {
                ANS=min(ANS,gotime[i][k]);
            }
        }
    }
    if(ANS==1000000)
    {
        cout<<-1;
    }
    else{
        cout<<ANS;
    }
    cin>>ANS;
}

void FireField(int x, int y, int t)
{
    if (deathtime[x][y] == MAX_N)
    {
        deathtime[x][y] = t;
    }
    else
    {
        deathtime[x][y] = min(deathtime[x][y], t);
    }
    if (deathtime[x+1][y] == MAX_N)
    {
        deathtime[x+1][y] = t;
    }
    else
    {
        deathtime[x+1][y] = min(deathtime[x+1][y], t);
    }
    if (deathtime[x][y+1] == MAX_N)
    {
        deathtime[x][y+1] = t;
    }
    else
    {
        deathtime[x][y+1] = min(deathtime[x][y+1], t);
    }
    if (x-1>=0&&deathtime[x-1][y] == MAX_N)
    {
        deathtime[x-1][y] = t;
    }
    else if(x-1>=0)
    {
        deathtime[x-1][y] = min(deathtime[x-1][y], t);
    }
    if (y-1>=0&&deathtime[x][y-1] == MAX_N)
    {
        deathtime[x][y-1] = t;
    }
    else if(y-1>=0)
    {
        deathtime[x][y-1] = min(deathtime[x][y-1], t);
    }
}