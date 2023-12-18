#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
Problem E
*/
int n, m, k, total;
char mat[22][22]; // 定义地图矩阵
bool gobefore[22][22] = {0};
int dir[4][2] = {
    {-1, 0}, // 上（左上角的坐标为（0,0）
    {1, 0},  // 下
    {0, -1}, // 左
    {0, 1}   // 右
};
struct Point
{
    int x;
    int y;
    vector<int> step; // 记录过程
    // vector<Point>had_gone;
};
Point beginpoint, endpoint;
// 结果数组
vector<vector<int>> vec;
// 函数声明：
void BFS(); // 广度搜索
bool check(Point x);
bool SamePoint(Point a, Point b);
void DFS(Point p, int step);
// bool step_bigger_than_k(Point p);
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            cin >> mat[i][k];
            if (mat[i][k] == '+')
            {
                beginpoint.x = i;
                beginpoint.y = k;
            }
            if (mat[i][k] == '*')
            {
                endpoint.x = i;
                endpoint.y = k;
            }
        }
    }
    gobefore[beginpoint.x][beginpoint.y] = 1;
    DFS(beginpoint, 0);   // 广度搜索
    bool isoutput = true; // 表示是否已经输出过答案了,true代表没有，false代表输出过了
    if (total != 0)       // 存在答案
    {
        for (int i = 0; i < total; i++) // 遍历搜索答案
        {
            vector<int> aaa = vec[i];
            int length = aaa.size();
            if (length == k) // 长度和指定一样哦
            {
                isoutput = false;
                for (int j = 0; j < aaa.size(); j++)
                {
                    cout << aaa[j] << " ";
                }
                cout << endl;
            }
        }                     // 这里已经遍历完total数组了
        if (isoutput == true) // 这里说明还没有答案被输出过捏
        {
            cout << "No way";
        }
    }
    else // 没有答案直接输出no way
    {
        cout << "No way";
    }
}

void DFS(Point p, int step)
{
    if (step == k && SamePoint(p, endpoint))
    {
        vec.push_back(p.step);
        total++;
        return;
    }
    if (step >= k) // 没希望了
    {
        return;
    }
    Point head = p, next;
    for (int i = 1; i <= 4; i++) // 按照左上右下四个方向顺时针逐一搜索
    {
        next = head;            // 先让下一个点等于队列首点
        vector<int> a = {2, 4}; //, 2, 4, 2, 3, 2, 3, 2, 3, 1, 3, 2 , 4
        if (equal(a.begin(), a.end(), next.step.begin(), next.step.end()))
        {
            // cout << "HI" << endl;
        }
        while (check(next)) // 如果这个点还可以继续的话
        {
            next.x = next.x + dir[i - 1][0];
            next.y = next.y + dir[i - 1][1];
            if (SamePoint(next, endpoint)) // 走的过程中就经过了这个终点
            {
                gobefore[next.x][next.y] = 1;
                next.step.push_back(i);
                vec.push_back(next.step);
                total++;
                return;
            }
        }
        next.x = next.x - dir[i - 1][0];
        next.y = next.y - dir[i - 1][1];
        if (gobefore[next.x][next.y] == 1)
        {
            continue;
        }
        // 走到头了：
        if (!SamePoint(head, next) && check(next)) // 如果next和head的点不是同一个
        {
            gobefore[next.x][next.y] = 1;
            next.step.push_back(i);
            // dfsTime++; cout << dfsTime << endl;
            DFS(next, next.step.size());
            gobefore[next.x][next.y] = 0;
        }
    }
}
bool check(Point x)
{
    if (x.x <= n && x.x > 0 && x.y <= m && x.y > 0 && mat[x.x][x.y] != '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool SamePoint(Point a, Point b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    else
        return false;
}
// void BFS()//广度搜索
//{
//	queue<Point> q;
//	beginpoint.had_gone.push_back(beginpoint);
//	q.push(beginpoint);
//	while (!q.empty())
//	{
//		Point head = q.front();
//		q.pop(); Point next;
//		if (SamePoint(head, endpoint))
//		{
//			total++;//方案++
//			vec.push_back(head.step);//将点当中的过程加入道数组当中
//			continue;//继续下一个循环，这个点已经是重点了
//		}
//		for (int i = 1; i <= 4; i++)//按照左上右下四个方向顺时针逐一搜索
//		{
//			next = head;//先让下一个点等于队列首点
//			while (check(next))//如果这个点还可以继续的话
//			{
//				next.x = next.x + dir[i - 1][0];
//				next.y = next.y + dir[i - 1][1];
//			}
//			next.x = next.x - dir[i - 1][0];
//			next.y = next.y - dir[i - 1][1];
//			if (gobefore[next.x][next.y] == 1)
//			{
//				continue;//凉了，直接下一个循环吧
//			}
//			if (!SamePoint(head, next))//如果next和head的点不是同一个
//			{
//				bool isgone = false;
//				for (int i = 0; i < next.had_gone.size(); i++)
//				{
//					if (SamePoint(next, next.had_gone[i]))//这个点已经走过了捏
//					{
//						isgone = true;
//					}
//				}
//				if (!isgone)//&&!step_bigger_than_k(next)
//				{
//					next.had_gone.push_back(next);
//					next.step.push_back(i);//记录行走
//					gobefore[next.x][next.y] = 1;
//					q.push(next);//放入队列当中
//				}
//			}
//
//		}
//	}
//
// }