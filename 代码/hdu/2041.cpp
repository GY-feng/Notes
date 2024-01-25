#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int dp[45];
void solve(int n)
{
    memset(dp, 0, sizeof(dp)); // dp置为0
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    // 枚举楼梯数，在第i阶楼梯有dp[i]种走法
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        solve(tmp);
        cout << dp[tmp] << endl;
    }
}