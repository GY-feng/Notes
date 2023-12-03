#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a,b;
int search(int x );
int main()
{
    cin>>n>>m;
    int j=0;
    a.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin>>j;
        a.push_back(j);
    }
    for (int i = 0; i < m; i++)
    {
        int c=0;
        cin>>c;
        b.push_back(c);
    }
    for (int i = 0; i < m; i++)
    {
        cout<<search(b[i])<<endl;
    }
    
    cin>>n;
}
int search(int x )
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(a[mid]<=x)l=mid;
        else r=mid-1;
    }
    if(l!=r)
    {
        if(x>a[l])
    {
        return l;
    }
        if(x>a[r])
    {
        return r;
    }
    }
    if(l==r)
    {
        if(a[l]<=x)//找到等于的情况了
    {
        return l;
    }
    }
    else
    {
        return 0;
    }
}
