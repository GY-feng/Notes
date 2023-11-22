#include<bits/stdc++.h>
using namespace std;
int price[50005];
int w=0,n=0,total=0;
int main()
{
    cin>>w>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>price[i];
    }
    int l=1,r=n;
    sort(price+1,price+n+1);
    while(l<=r)
    {
        if(price[l]+price[r]<=w)
        {
            l++,r--,total++;
        }
        else
        {
            r--,total++;
        }
    }
    cout<<total;
    cin>>n;
}