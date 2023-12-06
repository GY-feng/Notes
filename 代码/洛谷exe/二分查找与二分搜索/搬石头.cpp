#include<bits/stdc++.h>
using namespace std;
int L,N,M,stones[50005],stonedis_front[50005],stonedis_behine[50005];
#define INF 1e9
int Find(int l,int r);//返回的是最大值
int main()
{
    cin>>L>>N>>M;
    for (int i = 1; i <= N; i++)
    {
        cin>>stones[i]; 
    }
	stones[N+1]=L;//N+1才是终点捏
    cout<<Find(1,L);
    cin>>N;
}
bool P(int x)
{
    int k=0;//计数器
    int i=0;//下一块石头的编号
    int now=0;//要跳石头的人目前的位置
    while(i<N+1)//N不是终点，N+1才是
    {
        i++;
        if(stones[i]-stones[now]<x)
        {
            k++;//要移石头
        }
        else
        {
            now=i;//不需要移走的捏
        }
    }
	if(k>M) return false;
	else return true;
}
int Find(int l,int r)//返回的是最大值
{
    int ans,mid;
    while (l<=r)
    {
        mid=l+r>>1;
        if(P(mid))
        {
            ans=mid;l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}