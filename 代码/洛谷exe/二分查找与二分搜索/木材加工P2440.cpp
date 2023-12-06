#include<bits/stdc++.h>
using namespace std;
const int MAX=100000005;
int n,k;//原木的数量，需要得到的小段的数量
//二分想法：存在某个最大的长度L，超过L则切不到那k段，小于L才能切成那么多段
int trees[MAX];
bool pd(int x)
{
    int num=0;
    for (int i = 0; i < n; i++)
    {
        num+=trees[i]/x;
    }
    if(num>=k) return true;
    else return false;
}
int main()
{
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>trees[i];
    }
    int l=1,r=MAX,mid=0,ans=0;
	//int times=0;
    while (l<=r)
    {
        mid=l+r>>1;
        if(pd(mid))//在可以满足的情况下，应当尽量找大的值
        {
            ans=mid;
            //l=mid-1;
            l=mid+1;
        } 
        //else r=mid+1;
        else r=mid-1;
    }
    cout<<mid;
    cin>>n;
}