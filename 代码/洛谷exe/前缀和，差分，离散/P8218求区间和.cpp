#include<bits/stdc++.h>
using namespace std;
/*
给定n 个正整数组成的数列,m 个区间[l,r]分别求这 m 个区间的区间和。
*/
int n=0,m;
int numbers[100005],sum[100005];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>numbers[i];
        sum[i]=sum[i-1]+numbers[i];
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int l=0,r=0;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    cin>>n;
}