#include<bits/stdc++.h>
using namespace std;
//
int t=0,tmp=0,b,total=0;
vector<int> example;
//
//函数的 声明：
void bfs(int nowfloor);
bool mod1(int x)
{
    if(x%3==1)
        return true;
    else
        return false;
}
int main()
{
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>tmp>>b;
        bfs(tmp);cout<<total<<endl;
        total=0;
    }
    cin>>t;
}
//求可行解,所以采用DFS
void bfs(int nowfloor)
{
    if(nowfloor<=0)
    {
        return;
    }
    if(nowfloor==1)//到达一层，递归结束
    {
        total++;return;
    }
    if(mod1(nowfloor))//如果可以mod3余1
    {
        bfs(nowfloor-3);
    }
    bfs(nowfloor-1);
    bfs(nowfloor-2);
}