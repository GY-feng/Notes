#include<bits/stdc++.h>
using namespace std;
int Wx,Wy,num;//表示有Wx行，Wy列;用num统计可走的位置有多少
char room[23][23];
struct node//表示每个节点
{
        int x;
        int y;
};
int dir[4][2]={
{-1,0},//左（左上角的坐标为（0,0）
{0,-1},//上
{1,0},//右
{0,1}};//下
int main()
{
    int x,y, dx,dy;//dx和dy表示起点的坐标
    while(cin>>Wx>>Wy)
    {
        if(Wx==0&&Wy==0)
        {
            break;
        }
        for(y=0;y<Wy;y++)
        {
            for(x=0;x<Wx;x++)
            {
                cin>>room[x][y];
                if(room[x][y]=='@')//是起点呢
                {
                    dx=x;dy=y;
                }
            }
        }
    num=0;
    BFS(dx,dy);
    cout<<num<<endl;
    }
}
bool cheack_in_room(int x,int y)
{
    return x<Wx&&x>=0&&y>=0&&y<Wy;
}
void BFS(int dx,int dy)
{
    num=1;
    queue <node> q;
    node start,next;
    start.x=dx,start.y=dy;
    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();
    }
    for (int i = 0; i < 4; i++)//按照左上右下四个方向顺时针逐一搜索
    {
        next.x=start.x+dir[i][0];
        next.y=start.y+dir[i][1];
        if(cheack_in_room(next.x,next.y)&&room[next.x][next.y]=='.')
        {
            room[next.x][next.y]=='#';
            num++;
            q.push(next);
        }
    }    
}
