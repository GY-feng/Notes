#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    vector<int>a(n),b(m);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++)
    {
        int x=b[i];
        int l=0,r=n-1;//左右的下标
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(a[mid]==x)
            {
                cout<<"YES"<<endl;
                break;
            }
            if(a[mid]>x)
            {
                r=mid;
            }
            if(a[mid]>x)
            {
                l=mid;
            }
        }
        if(l==r&&a[l]==x)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(a[l]==x||a[r]==x)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}