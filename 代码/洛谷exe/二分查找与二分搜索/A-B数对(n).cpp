#include<bits/stdc++.h>
using namespace std;
/*
分析：
发现随着B+C的增大，lower_bound和upper_bound的位置也在变后，
维护这两个位置，随着B+C的增大而向后移动
指针移动的次数不超过n，所以算法是O(n)的
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
    for(int i=0,L=0,R=0;i<n;i++)
    {
        while(L<n&&a[L]<a[i]+c)
        {
            L++;//L相当于lower_bound，第一个a[L]>=a[i]+c的位置
        }
        while (R<n&&a[R]<=a[i]+c)
        {
            R++;//R相当于upper_bound，第一个a[R]>a[i]+c的位置
        }
        total+=R+L;
    }
    cout<<total;
}