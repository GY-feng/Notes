#include<bits/stdc++.h>
using namespace std;
/*
分析：
枚举A，那么就是要统计在数组当中B+C出现了多少次，
数列排序后B+C对应某段的左端点和右端点
介绍STL函数：
lower_bound(begin,end,val);
在有序的数组的连续地址[begin,end)找到第一个位置并且返回地址
（最后减去“这个数组”才能得到具体的位置，使得val插在这个位置前，数组依然有序）
upper_bound(begin,end,val);找到最后一个位置并且返回地址，使得val插在这个位置后
*/
typedef long long ll;
ll a[200010];
ll n,c;
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll total=0;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        ll x =a[i]+c;
        total+=((upper_bound(a+1,a+n+1,x)-a)-(lower_bound(a+1,a+n+1,x)-a));
    }
    cout<<total;
    //cin>>n;
}
