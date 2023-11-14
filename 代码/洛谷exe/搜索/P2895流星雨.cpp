#include<iostream>
#include<queue>
using namespace std;
int M, plan = -1;
struct Stars
{
    int x;
    int y;
    int t;
}star[50005];
struct Point
{
    int x;
    int y;
};
int place[310][310];
//函数的声明：
void Fire(int x, int y);
int main()
{
    cin >> M;
    for (int i = 0; i < 301; i++)
        for (int k = 0; k < 301; k++)
            place[i][k] = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> star[i].x >> star[i].y >> star[i].t;
    }
    //广度优先搜索
    queue<Point> q;
    q.push(Point{ 0, 0 });
    Point head;
    int t = 0;
    while (q.size())
    {
        head = q.front(); q.pop();//人物所在的地方
        if (t > star[M - 1].t)
        {
            plan = q.size();
            break;
        }
        for (int i = 0; i < M; i++)//先预判一下流星雨
        {
            if (star[i].t == t)
            {
                Fire(star[i].x, star[i].y);
            }
        }
        if ((head.x - 1) >= 0 && place[head.x - 1][ head.y] == 0)
            q.push(Point { head.x - 1, head.y });
        if ((head.y - 1) >= 0 && place[head.x][ head.y - 1] == 0)
            q.push(Point{ head.x, head.y - 1 });
        if ((head.x + 1) < 300 && place[head.x + 1][head.y] == 0)
            q.push(Point { head.x + 1, head.y });
        if ((head.y + 1 )< 300 && place[head.x][ head.y + 1] == 0)
            q.push(Point { head.x, head.y + 1 });
        t++;
        //else
            //cout<<"4个一个都没执行";     
        //Fire(head.x,head.y);
    }
    cout << plan;
    cin >> plan;
}
void Fire(int x, int y)
{
    place[x][y] = 1;
    if (x - 1 >= 0)
    {
        place[x - 1][y] = 1;//左边改1
    }
    if (y - 1 >= 0)
    {
        place[x][y - 1] = 1;//下面改成1
    }
    place[x + 1][y] = 1;
    place[x][y + 1] = 1;
}
