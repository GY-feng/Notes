#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,b[5010],a[1000010],minn=1e9,maxx;
long long ans;
const int mod=1e9+7;
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];//输入
		minn=min(minn,a[i]);//找出最小的ai
		maxx=max(maxx,a[i]);//找出最大的ai
		b[a[i]]++;//数组计数
	}
	for(int i=minn+1; i<=maxx; i++)//这里从最小量+1开始枚举，是因为最小量不可能有两个比它更小的两组成
	{
		if(b[i]>1)//如果这个数字有一个以上
			for(int j=minn; j<=i/2; j++)//开始枚举
				if(b[j]>=1&&b[i-j]>=1)//如果他可以被两个比他小的两组成
				{
					if(j*2!=i)ans=(ans+(b[i]*(b[i]-1)/2)*b[j]*b[i-j]%mod)%mod;//统计
					else if(b[j]>1)ans=(ans+((b[i]*(b[i]-1)/2)*(b[j]*(b[j]-1)/2)%mod)%mod)%mod;//统计
				}
	}
	cout<<ans%mod;//输出
	return 0;
}
//四重循环超了！！！
