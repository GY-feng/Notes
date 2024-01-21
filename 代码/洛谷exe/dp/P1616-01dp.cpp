#include<bits/stdc++.h>
using namespace std;
int t,m;
struct medicine
{
    int time;
    int value;
}med[10011];
int dp[10011][100000001];
//dp[i][j]表示将前i个物品装入容量为j的背包中所能获得的最大价值
int solve()
{
    memset(dp,0,sizeof(dp));
    for (int  i =1; i <=m; i++)//枚举前X种草药
    {
        for (int j = 0; j <=t; j++)//枚举背包的容量
        {
            if(med[i].time>j)//超出背包容量了，不可以加入哦,所以这个地方的最大价值和第前i-1个物品加入到背包中是一样的。
            {
                dp[i][j]=dp[i-1][j];
            }  
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][i-med[i].time]+med[i].value);
            }  
        }
    }
    return dp[m][t];
}
//上面的solve方法会超出空间限制，所以改用下面的方法：
int dp2[10000001];
int solve2()
{
    memset(dp2,0,sizeof(dp2));
    for (int  i =1; i <=m; i++)//枚举前X种草药
    {
        for (int j = t; j>med[i].time; j--)
        {
            dp2[j]=max(dp2[j],dp2[j-med[i].time]+med[i].value);
        }
        
    }
    return dp2[t];
}
int main()
{
    cin>>t>>m;//采药的时间 t 和代表山洞里的草药的数目m。
    for (int i = 1; i <= m; i++)
    {
        cin>> med[i].time>>med[i].value;
    }
    cout<<solve()<<endl;
}