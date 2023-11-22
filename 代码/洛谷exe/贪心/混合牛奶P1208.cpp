#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Milk
{
    int id;
    int money;
    int nums;
}milk[5005];

int main()
{
    cin>>n>>m;//所需牛奶的总量，提供牛奶的农民的个数
    for(int i=0;i<m;i++)
    {
        cin>>milk[i].money>>milk[i].nums;
    }
}