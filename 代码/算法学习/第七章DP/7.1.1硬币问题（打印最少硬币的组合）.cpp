#include<bits/stdc++.h>
using namespace std;
//打印最少硬币的组合：要增加一个记录表Min_path[i]记录金额i所需的最后一个硬币，利用这个数组倒推就能得到所有的硬币

const int MONEY=251;//最多金额
const int VALUE=5;//5种面值
int type[VALUE]={1,5,10,25,50};
int Min[MONEY];//每个金额对应的最少的硬币数量
int Min_path[MONEY]={0};//记录最小硬币的路径
void solve()
{
    for(int k=0;k<MONEY;k++)
        Min[k]=INT_MAX;
    Min[0]=0;
    for(int j=0;j<VALUE;j++)
        for(int i=type[j];i<MONEY;i++)
            if(Min[i]>Min[i-type[j]]+1)
            {
                Min_path[i]=type[i];//在每个金额上记录路径，即某个硬币的面值
                Min[i]=min(Min[i],Min[i-type[j]]+1);
            }
}//不断“优化”最优解，1个，5个，10个，25个...
void print_ans(int *Min_path,int s )
{
    while(s)
    {
        cout<<Min_path[s]<<" ";
        s=s-Min_path[s];
    }
}
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