#include<bits/stdc++.h>
using namespace std;
int n,c;
int house[100005];//牛牛屋
bool P(int x)
{
    int k = 0, lastniuniu = -1000000000; // 记录上一头牛牛的坐标
    for (int i = 1; i <= n; i++)
    {
        if (house[i] - lastniuniu >= x)
        {
            lastniuniu = house[i];
            k++;
        }
    }
    return k >= x;
}

int main()
{
    cin>>n>>c;
    for (int i = 1; i <= n; i++)
    {
        cin>>house[i];
    }
    sort(house+1,house+n+1);
    const int MAX=house[n];
    int l=0,r=MAX,ans=0;
    while (l<=r)
    {
        int mid=l+r>>1;
        if(P(mid))//可以满足，说明还可以继续变大
        {
            ans=mid;l=mid+1;
        }
        else//说明答案在更小的地方
        {
            r=mid-1;
        }
    }
    
}