#include<bits/stdc++.h>
using namespace std;
int n,m;//n是菜品，m是金额
//int meaus[105];//有105道菜
int meaus[101];
int dp[10005][105]={0};
void solve2();
int main()
{
    //meaus.push_back(0);
    //cin>>n>>m;
    int  a=0;
    for (int i = 1; i <n; i++)
    {
        cin>>meaus[i];
    }
    //int ans[m]={0};
    //sort(meaus.begin(),meaus.end());
    solve2();
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         ans[i]+=dp[i][j];
    //     }
    // }
    // cout<<ans[n];
    cin>>n;
}
void solve2()
{
    for(int i=1;i<=n;i++)//菜品
    {
        for(int j=1;j<=m;j++)//金额
        {
            /*
            这三个方程，每一个都是在吃与不吃之间抉择。若钱充足，
            办法总数就等于吃这道菜的办法数与不吃这道菜的办法数之和；
            若不充足，办法总数就只能承袭吃前i-1道菜的办法总数。
            */
            if(j==meaus[i])dp[i][j]=dp[i-1][j]+1;
            if(j>meaus[i])dp[i][j]=dp[i-1][j]+dp[i-1][j-meaus[i]];
            if(j<meaus[i])dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][m];
}