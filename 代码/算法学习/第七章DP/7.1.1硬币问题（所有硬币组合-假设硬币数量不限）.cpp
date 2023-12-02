#include<bits/stdc++.h>
using namespace std;
const int MONEY=251;//定义最大金额
int type[5]={1,5,10,25,50};//5种面值
int dp[MONEY]={0};
//在假设所有的硬币都有无限个的情况下：
void solve()
{
    dp[0]=1;
    for(int i=0;i<5;i++)
    {
        for(int j=type[i];j<MONEY;j++)
            dp[j]=dp[j]+dp[j-type[i]];
            /*
            找dp[i]与dp[i-1]之间的递推关系
            开始只用1分硬币推导，后面用更大的面值一步步加上之前推导的结果
            dp[i]=dp[i]+dp[i-1]//这里的1为1元的意思
            i>=5时，金额s的数量=从s当中减去5的组合
            再继续处理10，25，50的情况
            */
    }
}
const int coin=101;
int dp2[MONEY][coin]={0};
//硬币只有100个=>建立状态转移矩阵，横向是金额，纵向是硬币数
void Solve2()
{
    dp2[0][0]=1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < coin; j++)
        {
            for (int k = type[i]; k < MONEY; k++)
            {
                dp2[k][j]+=dp2[k-type[i]][j-1];
            }
            
        }
        
    }
       
}
int main()
{

}