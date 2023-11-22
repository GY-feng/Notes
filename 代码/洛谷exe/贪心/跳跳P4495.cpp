#include<bits/stdc++.h>
using namespace std;
#define int long long
int n=0;
int heights[310];
int hp=0;
signed main()
{
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        cin>>heights[i];
    }
    sort(heights+1,heights+n+1);
    int l=0,r=n;
   // int nowstone=heights[r];
    //r--;
    //hp+=nowstone*nowstone;
    while (l<r)
    {
        hp+=(heights[l]-heights[r])*(heights[l]-heights[r]);
        l++;
        hp+=(heights[l]-heights[r])*(heights[l]-heights[r]);
        r--;
    }
    
    cout<<hp;
    cin>>n;
    return 0;
}