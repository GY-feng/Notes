#include<bits/stdc++.h>
using namespace std;
int n,m;
//dp[i][j]表示第i种生物可以被j吃,然后由小到大按列循环如eat[2][j]
int eat[5005][5005];
long long dp[5005];
int main()
{
    cin>>n>>m;
    int t_a=0,t_b=0;
    for (int i = 0; i < m; i++)
    {
        cin>>t_a>>t_b;
        eat[t_a][t_b]=1;
    }
    dp[1]=0;//第1种生物谁也吃不掉
    for (int i = 2; i <= n; i++)//从第二种生物开始遍历
    {
        int tmp=0;
        for (int j = i-1; i >=1; i--)//吃不掉自己，所以从大往小进行遍历
        {
            if(eat[j][i]==1)//存在吃的关系
            {
                //i可以将j吃掉
                tmp+=eat[j][i];//我吃！
                tmp+=dp[j];//可吃
            }
        }
        dp[i]=tmp;
    }
    sort(dp+1,dp+1+n);
    cout<<dp[n+1];
    cin>>n;
}