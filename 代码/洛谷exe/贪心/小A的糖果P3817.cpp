#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,ans;
ll box[100005];
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>box[i];
    }
    ll num=0;
    for(int k=1;k<=n;k++)
    {
        if(box[k]+box[k-1]>x)
        {
            //贪心所在：优先吃前面的，使得后面尽可能小
            num=box[k]+box[k-1]-x;
            box[k]-=num;
            ans+=num;
        }
    }
    cout<<ans;
    //cin>>num;
}