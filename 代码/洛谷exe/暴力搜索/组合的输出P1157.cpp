#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int n,r;
int stringToInt(const std::string& str);
int a[30];
int main()
{
    //cout<<"BEGIN"<<endl;
    cin>>n>>r;
    for(int S=(1<<n)-1;S>=0;S--)//从全集枚举到0
    {
        int cnt=0;
        for (int i = 0; i < n; i++)
        {
            if(S&(1<<i))//检查S的第i位是否为1
                a[cnt++]=i;//分离记录每一位
        }
        if(cnt==r)
        {
            for (int i = r-1; i>=0; i--)
            {
                    printf("%3d",n-a[i]);
                    puts(" ");
            }
            
        }
        
    }
}