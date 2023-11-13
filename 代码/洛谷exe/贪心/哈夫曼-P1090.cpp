#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n;
int fruits[10005];
typedef long long ll;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin>>n;//果子的种类数
    priority_queue<ll,vector<ll>,greater<ll> >q;
    int a=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
        //fruits[i]=a;
    }
    // sort(fruits,fruits+n);
    // for(int i=0;i<n;i++)
    // q.push(fruits[i]);
    ll result=0;
    //result=q.top();
    while(q.size()>1)
    {
        ll a=q.top();q.pop();
        ll b=q.top();q.pop();
        q.push(a+b);
        result+=(a+b);
    }
    q.pop();
    //result+=q.top();
    cout<<result;
    int aaaaaa=0;
    cin>>aaaaaa;
}