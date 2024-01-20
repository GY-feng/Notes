#include<bits/stdc++.h>
using namespace std;
const int COIN=101;//硬币的最大个数
const int MONEY=251;//最大金额
int dp[MONEY][COIN]={0};
int type[5]={1,5,10,20,50};
void solve()
{
    dp[0][0] = 1;
    for (int i = 0; i < 5; i++)//枚举5种硬币
    {
        for (int j = 1; j<COIN;j++)//硬币的个数没有达到上限,这里从1个硬币开始枚举
        {
            for (int k = type[i]; k < MONEY; k++)
            {
                dp[k][j]+=dp[k-type[i]][j-1];//转移矩阵+=dp[待求金额-面值][硬币个数-1]；
            }
            
        }
    }
}
int main()
{
    int s;
    int ans[MONEY]={0};
    solve();//计算状态转移矩阵
    for(int i=0;i<MONEY;i++)
    {
        for (int j = 0; j < COIN; j++)//打表计算每个金额有多少种组合方案
        {
            ans[i]+=dp[i][j];//从0开始计算
        }
        while(cin>>s)
        {
            cout<<ans[s]<<endl;
        }
        
    }
}