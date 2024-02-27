#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Friend_
{
    ll lose,win,use;
}friend_[1005];

int main()
{
    int n,x;//n组数据，x个药水
    cin>>n>>x;
    for (int i = 1; i <= n; i++)
    {
        cin>>friend_[i].lose>>friend_[i].win>>friend_[i].use;
    }
    int  dp[1100][1100];//dp[i][k]表示将前i个物品装入容量为k的背包所能获得的最大价值
    for (int i = 1; i <= n; i++)
    {
            for (int k = 0; k <= x; k++)
            {
                if (friend_[i].use>k)//药水用不了了
                {
                    dp[i][k]=dp[i-1][k]+friend_[i].lose;
                }
                else
                {
                    dp[i][k]=max(dp[i-1][k]+friend_[i].lose,dp[i-1][k-friend_[i].use]+friend_[i].win);
                }
            }         
    }
    cout<<dp[n][x]<<endl;
}