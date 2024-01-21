#include<bits/stdc++.h>
using namespace std;
/*
求一个n层的三角形数塔，只能由头想下左或下右走，问可能走过的路径的最大数字和是多少
快速的方法：自底向上，dp[i][j]记录第i层第j个数开始向下走的数字和，一个节点算一次，有n^2个节点，复杂度n^2
*/
int 递推()
{
    int n=100;//有n层数塔
    int a[150][150];
    int dp[150][150];
    for (int j = 1; j <= n; j++)
    {
        dp[n][j]=a[n][j];//先计算最后的一层
    }
    for (int i = n-1; i >= 1; i--)//从倒数第二层一直向上走到第一层
    {
        for (int k = 1; k <=i; k++)
        {
            //从左边走上来，或者从右边走上来，取其中较大的
           dp[i][k]=a[i][k]+max(dp[i+1][k],dp[i+1][k+1]);     
        }  
    } 
}
int n=100;//有n层数塔
int a[150][150];
int dp[150][150];
int dfs(int i,int j)
{
    if(i==n)
    {
        return a[i][j];
    }
    return dp[i][j]=max(dfs(i+1,j),dfs(i+1,j+1))+a[i][j];//从左边走上来或者右边走上来
}
//上述的这种搜索方式，复杂度在2^n，太慢了！
int dfs_ver2(int i,int j)//先前已经将dp全部设置成-1
{
    if(i==n)
        return a[i][j];
    if(dp[i][j]>=0)//记忆存在，不需要重新计算
    {
        return dp[i][j];
    }
    return dp[i][j]=max(dfs(i+1,j),dfs(i+1,j+1))+a[i][j];
}
int main()
{

}