#include<bits/stdc++.h>
using namespace std;
double n,m,k,l,r;
bool pd(double x){//判断当前答案是否满足 
	return (pow(1.0/(1.0+x),k)>=1-n/m*x);//pow函数，上文已讲
}
int main(){
	cin>>n>>m>>k;
   	///////////////////////二分模板
	l=0;r=10;//月利率可能大于1
	while(r-l>=0.0001){//注意精度问题 
		double mid=(l+r)/2;
		if(pd(mid))r=mid;
		else l=mid;
	}
   	///////////////////////
	cout<<fixed<<setprecision(1)<<l*100;//输出一位小数哦 
    cin>>n;
	return 0;
} 