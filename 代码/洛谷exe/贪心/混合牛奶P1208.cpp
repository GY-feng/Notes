#include<bits/stdc++.h>
using namespace std;
int n,m,total=0,money_need;
struct Milk
{
    int id;
    int money;
    int nums;
}milk[5005];
int cmp(Milk a,Milk b)
{
    return a.money<b.money;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;//所需牛奶的总量，提供牛奶的农民的个数
    for(int i=1;i<=m;i++)
    {
        milk[i].id=i;
        cin>>milk[i].money>>milk[i].nums;
    }
    sort(milk+1,milk+1+m,cmp);
    bool next=true;
    for (int i =1 ; i <=n; i++)
    {
        if((total+milk[i].nums)<n)
        {
            total +=milk[i].nums;
            money_need+=milk[i].nums*milk[i].money;
        }
        if((total+milk[i].nums)==n)
        {
            break;
        }
        else
        {
            int rest=milk[i].nums-total;
            money_need+=rest*milk[i].money;
        }
    }
    cout<<money_need;
    
}