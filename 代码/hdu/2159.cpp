#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,a,b;

int main()
{
    //还需的经验值，保留的忍耐度，怪的种数和最多的杀怪数
    while(1)
    {
        cin>>n>>m>>k>>s;
        int exp[25]={0};//exp[a]=b//代表杀怪获得的经验值和忍耐度
        for (int i= 0;i <k;i++)
        {
            cin>>a>>b;
            exp[a]=b;
        }
        int dp[105][105];
        //得到能在忍耐度下的最大经验值，然后和还需的最大经验值进行对比，输出背包剩余容量

        for(int j=0;j<k;j++)
        {
            
        }
    }
}
int dp()
{

}