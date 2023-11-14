#include<bits/stdc++.h>
using namespace std;
int M;
struct Stars
{
    int x;
    int y;
    int t;
}star[50005];
int time=0;
int nowx=0,nowy=0;
int place[310][310];
int main()
{
    cin>>M;
    //广度优先搜索
    queue<Stars> q;
    q.push(star[0]);
    Stars head;
    while(q.size())
    {
        head=q.front();q.pop();//流星将要坠落的地方
        Fire(head.x,head.y);
    }
}
void Fire(int x,int y)
{
    place[x][y]=1;
    if(x-1>=0)
    {
        place[x-1][y]=1;//左边改1
    }
    if(y-1>=0)
    {
        place[x][y-1]=1;//下面改成1
    }
    place[x+1][y]=1;
    place[x][y+1]=1;
}