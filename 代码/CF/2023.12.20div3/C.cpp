#include<bits/stdc++.h>
using namespace std;
int t;//t个测试用例
int main()
{
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        
    }
    
}
/*
暴力最后一关的位置
为了到达第k关，需要用k次机会获得前面所有关卡的第一次收益
然后剩下K-k次机会全部刷前k关最高收益管卡
用前缀和预处理，时间复杂度O(N)
*/
void solve()
{
    int n=0,k=0,tmp=0;
    cin>>n>>k;//n代表着任务的数量,k代表着能做的最多的任务
    vector<int>a,b;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        b.push_back(tmp);
    }
    int exp=0;
    // for (int i = 1; i < n; i++)//i代表着最大能推进到多少关
    // {
    //     if(i>k)//模拟到的的关数大于能做的任务数了，就放弃
    //     {
    //         //Do SomeThing
    //         break;
    //     }
    //     else
    //     {
            
    //     }
    // }
    if(k>=n)//能将n个任务都完成一遍
    {
        //do something;
    }
    else//不能将n个任务全部完成一次
    {

    }
    
}