#include <bits/stdc++.h>
using namespace std;
char pulaze[305][305]; // 存储地图上的数据
int iswalk[305][305];  // 记录是否走过这个点
int n, m, time;
int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};
struct Point
{
    int x, y, step = 0;
};
Point finalpoint;
Point beginpoint;
vector<int> ans;
queue<Point> q;
//函数的声明：
void bfs(Point x, int time);
bool specialMove(Point x);
Point findSamePoint(Point x);
bool check(Point x);
int main()
{
    cin >> n >> m;
    string str = "";
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        for (int k = 0; k < m; k++)
        {
            if (str[k] == '=')
            {
                finalpoint = (Point){i, k + 1};
            }
            if (str[k] == '@')
            {
                beginpoint = (Point){i, k + 1};
            }
            pulaze[i][k + 1] = str[k];
        }
    }
    bfs(beginpoint, 0);
    int answer=1000000;
    for (int i = 0; i < ans.size(); i++)
    {
        min(answer,ans[i]);
    }
    cout<<answer;
    cin>>answer;
}
void bfs(Point x, int time)
{
    q.push(x);
    Point p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p.x == finalpoint.x && p.y == finalpoint.y)
        {
            ans.push_back(p.step);
            continue;
        }
        iswalk[p.x][p.y] = 1; // 表示这点已经走过了
        p.x = p.x + 1;
        p.y = p.y;
        if (check(p)) // 如果这个地方可以走捏；
        {
            if (specialMove) // 如果存在特殊移动
            {
                Point specialPoint = findSamePoint(p);
                specialPoint.step=p.step+1;
                q.push(specialPoint);
                //bfs(specialPoint, time + 1);
            }
            else
            {
                p.step+1;
                q.push(p);
            }
        }
        p.x--;

                p.x = p.x - 1;
        p.y = p.y;
        if (check(p)) // 如果这个地方可以走捏；
        {
            if (specialMove) // 如果存在特殊移动
            {
                Point specialPoint = findSamePoint(p);
                specialPoint.step=p.step+1;
                q.push(specialPoint);
                //bfs(specialPoint, time + 1);
            }
            else
            {
                p.step+1;
                q.push(p);
            }
        }
        p.x++;
                p.x = p.x;
        p.y = p.y+1;
        if (check(p)) // 如果这个地方可以走捏；
        {
            if (specialMove) // 如果存在特殊移动
            {
                Point specialPoint = findSamePoint(p);
                specialPoint.step=p.step+1;
                q.push(specialPoint);
                //bfs(specialPoint, time + 1);
            }
            else
            {
                p.step+1;
                q.push(p);
            }
        }
        p.y--;
                p.x = p.x;
        p.y = p.y-1;
        if (check(p)) // 如果这个地方可以走捏；
        {
            if (specialMove) // 如果存在特殊移动
            {
                Point specialPoint = findSamePoint(p);
                specialPoint.step=p.step+1;
                q.push(specialPoint);
                //bfs(specialPoint, time + 1);
            }
            else
            {
                p.step+1;
                q.push(p);
            }
        }
        p.y++;
    }
}
void dfs(Point p, int time)
{
    Point x;
    iswalk[p.x][p.y] = 1; // 表示这点已经走过了
    if (p.x == finalpoint.x && p.y == finalpoint.y)
    {
        ans.push_back(time);
        memset(iswalk, 0, sizeof(iswalk)); // 将是否走过的状态回归
        return;
    }

    x.x = p.x + 1;
    x.y = p.y;
    if (check(x)) // 如果这个地方可以走捏；
    {
        if (specialMove) // 如果存在特殊移动
        {
            Point specialPoint = findSamePoint(x);
            dfs(specialPoint, time + 1);
        }
        else
        {
            dfs(x, time + 1);
        }
    }

    x.x = p.x - 1;
    x.y = p.y;
    if (check(x)) // 如果这个地方可以走捏；
    {
        if (specialMove) // 如果存在特殊移动
        {
            Point specialPoint = findSamePoint(x);
            dfs(specialPoint, time + 1);
        }
        else
        {
            dfs(x, time + 1);
        }
    }

    x.x = p.x;
    x.y = p.y + 1;
    if (check(x)) // 如果这个地方可以走捏；
    {
        if (specialMove) // 如果存在特殊移动
        {
            Point specialPoint = findSamePoint(x);
            dfs(specialPoint, time + 1);
        }
        else
        {
            dfs(x, time + 1);
        }
    }

    x.x = p.x;
    x.y = p.y - 1;
    if (check(x)) // 如果这个地方可以走捏；
    {
        if (specialMove) // 如果存在特殊移动
        {
            Point specialPoint = findSamePoint(x);
            dfs(specialPoint, time + 1);
        }
        else
        {
            dfs(x, time + 1);
        }
    }
}
bool specialMove(Point x)
{
    char info = pulaze[x.x][x.y];
    if (info >= 65 && info <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Point findSamePoint(Point x)
{
    char info = pulaze[x.x][x.y]; // 找到info的地方了
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            if (pulaze[i][k] == info)
            {
                if (i != x.x && k != x.y) // 和传进来的原来的数字不是相等的
                {
                    return (Point){i, k};
                }
            }
        }
    }
}
bool check(Point x)
{
    if (x.x < 1 || x.y < 1 || x.x > n || x.y > m)
    {
        return false;
    }
    if (iswalk[x.x][x.y] > 0) // 这个点已经走过了
    {
        return false;
    }
    if (pulaze[x.x][x.y] == '#')
    {
        return false;
    }
}