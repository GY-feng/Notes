#include<bits/stdc++.h>
using namespace std;
//最少硬币问题
const int MONEY=251;//最多金额
const int VALUE=5;//5种面值
int type[VALUE]={1,5,10,25,50};
int Min[MONEY];//每个金额对应的最少的硬币数量
void solve()
{
    for(int k=0;k<MONEY;k++)
        Min[k]=INT_MAX;
    Min[0]=0;
    for(int j=0;j<VALUE;j++)
        for(int i=type[j];i<MONEY;i++)
            Min[i]=min(Min[i],Min[i-type[j]]+1);
}//不断“优化”最优解，1个，5个，10个，25个...
int main()//打表的思路
{
    int s;
    solve();
    while(cin>>s)
    {
        cout<<Min[s]<<endl;
    }
    return 0;
}