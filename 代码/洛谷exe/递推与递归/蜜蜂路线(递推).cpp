#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
int house[1010];
signed main()
{
    cin>>m>>n;
    house[1]=1,house[2]=1;//house[3]=2;
    for (int i = 3; i <= n-m+1; i++)
    {
        house[i]=house[i-1]+house[i-2];
    }
    cout<<house[n-m+1];
}