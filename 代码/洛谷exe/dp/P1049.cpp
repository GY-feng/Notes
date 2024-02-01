#include<bits/stdc++.h>
using namespace std;
int v,n;//箱子容量和物品总数
int vol[35];
int dp[35][35];//dp[i][j]表示将将前i个物品装入容量为j的背包的价值
int main()
{
    cin>>v>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>vol[i];//从下标1开始输入每个物品的体积
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <=v; j++)
        {
            //if(vol[i]>v)//这行是错误的，不是和最大的体积比较，而应当是和当前枚举的背包体积进行比较，这样才能不超过背包的最大值呢
            if (vol[i] > j) 
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-vol[i]]+vol[i]);
            }
        }
    }
    cout<<v-dp[n][v]<<endl;
}