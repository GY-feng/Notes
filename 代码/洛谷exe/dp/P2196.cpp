
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
分析：
因为路径的顺序一定是由小到大走的
从后面的地窖向前而数，用DP，dp[i]表示以第i个为起点，最多能挖到多少个地雷

*/
int n, l, k;
int a[25], c[25];
int connect[25][25];
int dp[25];
int main()
{
    // n<=20
    cin >> n;
    /// memset(connect, -1, sizeof(connect));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // 保存地窖当中的地雷个数
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> connect[i][j];
        }
    }

    dp[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        l = 0, k = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (connect[i][j] == 1 && dp[j] > l) // 记一下最大值
            {
                l = dp[j]; // 最大值记录一下
                k = j;
            }
        }
        dp[i] = l + a[i]; // 从i开始能挖到的最大的地雷数
        c[i] = k;         // k地窖是i地窖出发的最优路径(记录最优顺序)
    }
    k = 1; // 第一个地窖能哇的最大地雷数量

    for (int i = 2; i <= n; i++)
    {
        if (dp[i] > dp[1])
            k = i;
    }

    int maxx = dp[k];

    cout << k;
    k = c[k];
    while (k != 0)
    {
        cout << " " << k;
        k = c[k];
    }
    cout << endl;
    cout << maxx;
    cin >> n;
}
