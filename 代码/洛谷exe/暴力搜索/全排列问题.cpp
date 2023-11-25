#include<bits/stdc++.h>
using namespace std;
int n,a[10];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        a[i]=i;
    }
    bool isnext=true;
    do
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%5d",a[i]);
        }
        puts(" ");
    }while(next_permutation(a+1,a+n+1));
}