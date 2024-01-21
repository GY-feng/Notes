#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int dp[1005][1005]; //= { -1 };//这个地方只能将第一个元素改成-1而不能将所有元素如此
int a[1005][1005];
int dfs_plus(int i, int j)//第i行j个
{
    if (i == n)
    {
        return a[i][j];
    }
    if (dp[i][j] >= 0)//这个地方已经有记忆了
    {
        return dp[i][j];
    }
    return dp[i][j] = max(dfs_plus(i+1,j), dfs_plus(i+1,j+1)) + a[i][j];
}
int main()
{
    cin >> n;//行数
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = i + 1; j > 0; j--)
        {
            cin >> a[i][k];
            k++;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs_plus(0, 0) << endl;
    //cout << "FINISH" << endl;
}