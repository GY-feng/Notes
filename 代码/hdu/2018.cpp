#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int dp[55];
void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
}
int main()
{
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        // 牛牛的数量(dp[n])=前一年生的数量+四年前生的牛牛数量
        solve();
        cout << dp[n] << endl;
    }
}
