#include<bits/stdc++.h>
using namespace std;	
#define int long long

void init();

int m,n;	
int house[10005];	
 
signed main() 
{int a;
cin>>a;
init();
for(int i=0;i<a;i++)
{
 	cin>>m;	
 	cout<<house[m]<<endl;
}
cin>>m;
}
void init()
{
 	house[1]=2,house[2]=7;//house[3]=2;	
 	for (int i = 3; i <= 10005; i++)	
 	{	
 	house[i]=house[i-1]+4*(i-1)+1;	
 	}
}