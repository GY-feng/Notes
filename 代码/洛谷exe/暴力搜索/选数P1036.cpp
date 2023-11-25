#include<bits/stdc++.h>
using namespace std;
int n,k,total=0;
vector<int> num;
bool isPrime(int n);
int main()
{
    cin>>n>>k;//n个整数中选k个
    int g=0;
    for(int i=0;i<n;i++)
    {
        cin>>g;num.push_back(g);
    }
    int U=1<<n;//U-1就是全集<<n就是向1后面塞几个0
    for(int S=0;S<U;S++)//枚举所有子集
    {
        if(__builtin_popcount(S)==k)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(S&(1<<i))
                    sum+=num[i];
            }
            if(isPrime(sum))
                    total++;
        }
    }
    cout<<total;
    cin>>n;
}
bool isPrime(int n)
{
    if(n<=1)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}