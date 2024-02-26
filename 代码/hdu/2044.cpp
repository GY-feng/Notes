#include<bits/stdc++.h>
using namespace std;
void init();
int num[55]={0};
int main()
{
    int n=0,a,b;
    cin>>n;
    init();
    for (int i = 0; i < n; i++)//a,b不相等
    {
        
        cin>>a>>b;
        b=b-a+1;
        a=1;
        if(b<=3)
        {
            cout<<num[b]<<endl;
        }
        else
        {
            cout<<num[b]<<endl;
        }
    }
}
void init()
{
    num[1]=1;
    num[2]=1;
    num[3]=2;
    for(int i=4;i<55;i++)
    {
        num[i]=num[i-1]+num[i-2];
    }
}
