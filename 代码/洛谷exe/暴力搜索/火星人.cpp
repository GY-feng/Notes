#include<bits/stdc++.h>
using namespace std;
int N,M;
int a[10005];
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    //转化一下，就是求给定排序后的第m个排序
    for(;M--;)//m!=0就继续
    {
        next_permutation(a+1,a+N+1);
    }
    for (int i = 1; i <=N; i++)
    {
        cout<<a[i]<<" ";
    }
    
}