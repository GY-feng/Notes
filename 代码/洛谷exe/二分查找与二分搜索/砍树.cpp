#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll trees[1000005];
/*
分析，固然可以从1m往上一直枚举，但是复杂度是n×h太慢了
判断单调性：
当x超过某个数的时候，条件一定是不成立的，而当不超过这个数的时候，条件一定成立
完全符合二分条件！
*/
bool P(int h)
{
    ll total=0;
    for (int i = 0; i < n; i++)
    {
        if(trees[i]>h)
        {
            total+=trees[i]-h;
        }
    }
    return total>=m;
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
            cin>>trees[i];
    }
    sort(trees,trees+n);
    int L=0,R=1e9,ans,mid;
    while (L<=R)
    {
        if(P(mid=L+R>>1))
            ans=mid,L=mid+1;
            //为真，mid可以成为答案，真正的答案可能在mid的右侧，左端点右移动
        else R=mid-1;//答案在mid的左侧，右端点左移
    }
    cout<<ans;
    
}