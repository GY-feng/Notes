#include <iostream>
#include <algorithm>
using namespace std;
// P1101单词方阵
char word[] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
char mat[103][103];
char ansmat[103][103];
int n;
void dfs(int dr, int dc, int r, int c, int cut);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            cin >> mat[i][k];
            ansmat[i][k] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (mat[i][k] == 'y')
            {
                // 这里是起点了哇
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (mat[i + dr][k + dc] == 'i')
                        {
                            dfs(dr, dc, i, k, 0); // 方向，搜索
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (ansmat[i][k])
            {
                cout << mat[i][k];
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
// dr,dc是方向，r，c代表第一个字母'r'的坐标位置
void dfs(int dr, int dc, int r, int c, int cut)
{
    if (cut == 7)
    {
        for (int i = 1; i <= 7; i++)
        {
            ansmat[r - dr * i][c - dc * i] = 1; // 标记为保留
        }
    }
    if (r >= 1 && r <= n && c >= 1 && c <= n && mat[r][c] == word[cut])
    {
        dfs(dr, dc, r + dr, c + dc, cut + 1);
    }
    return;
}
