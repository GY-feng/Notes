#include <bits/stdc++.h>
using namespace std;
int n, m;
char fields[105][105];
int total = 0;
void search(int x, int y);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1}; // 此处千万要注意，是8个方向
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            cin >> fields[i][k];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            if (fields[i][k] == 'W')
            {
                // fields[i][k]=='.';
                search(i, k);
                total++;
            }
        }
    }
    cout << total;
    cin >> n;
}
// 代码升级：使用数组维护8个方向的搜索
void search(int x, int y)
{
    fields[x][y] = '.'; // 定义为搜索过了
    for (int i = 0; i <= 7; i++)
    {
        if (x<=n&&y<=m&&fields[x + dx[i]][y + dy[i]] == 'W') // 向右搜索,不用考虑越界问题，因为开大了
        {
            search(x + 1, y);
        }
    }
}
