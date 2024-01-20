//捡骨头问题：
#include<bits/stdc++.h>
using namespace std;
struct Bone{
    int val;
    int vol;
}bone[1011];//最大的骨头数量
int N,V;//骨头的数量和背包的体积
int dp[1011][1011];
int ans()
{
    memset(dp,0,sizeof(dp));
    //dp[i][k]表示把前i个物品装入容量为k的背包所能获得的最大价值
    for (int i = 1; i <= N; i++)
    {
        for (int k = 0; k <= V; k++)
        {
            if(bone[i].vol>k)//第i个物品太大了，装不下捏
            {
                dp[i][k]=dp[i-1][k];
            }
            else//第i个物品可以装得下
            {
                //
                dp[i][k]=max(dp[i-1][k],dp[i-1][k-bone[i].vol]+bone[i].val);
            }
        }
    }
    printplan(dp[N][V]);
    return dp[N][V];//返回最大价值
}
void printplan(int maxvalue)//输出01背包方案，回过头来看具体装了哪些物品
{
    vector<int> select;
    int i=N,w=V;
    while(i>0&&w>0)
    {
        if(dp[i][w]!=dp[i-1][w])
        {
            select.push_back(i-1);
            w-=bone[i-1].vol;
        }
        --i;
    }
}
int dp2[1011];
int ans_v2()//加入了滚动数组，以减少空间的消耗
{
    memset(dp2,0,sizeof(dp));
    //处理dp[][]时有个技巧：将它变成1维的dp[]以节省空间.
    //观察上面的二维表dp[][]可以发现，每一行是从上面一行算出来的，只和上面一行有关系，那么用新的一行覆盖掉上一行就可以
    //这个技巧很有用，可以防止超空间
    for (int i = 1; i <= N; i++)
    {
        for (int k = V; k>=bone[i].vol; k--)//反过来循环
        {
            /*
            为什么选择反向循环的原因主要与动态规划的性质有关。背包问题通常涉及到一个状态转移的过程，而在这个过程中，当前状态的计算可能会用到上一行的状态。
            反向循环的原因在于，如果我们正向循环进行状态转移，即从小到大地计算当前状态，可能会导致在计算当前状态时使用到了当前行中已经被更新过的状态，从而得到不正确的结果。
            */
            dp2[k]=max(dp2[k],dp2[k-bone[i].val]+bone[i].val);
        }
    }
    return dp2[V];
}
int main()
{
    cin>>N>>V;//数量和背包体积
    for (int i = 1; i <= N; i++)
    {
        cin>>bone[i].val;//每个骨头的价值
    }
    for (int k = 0; k <=N; k++)
    {
        cin>>bone[k].vol;//每个骨头的体积
    }
    cout<<ans()<<endl;
}