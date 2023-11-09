#include<bits/stdc++.h>
using namespace std;
int n,m,p;
const int MAXN=5005;
int fa[MAXN];

//声明；
void init_set(int n);//初始化集合，父节点设置为它本身
int find_Set(int x);//查找根节点
void union_set(int x,int y);//合并


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p;
    init_set(n);

    int m1,m2,p1,p2;
    for(int i=1;i<=m;i++)
    {
        cin>>m1>>m2;
        union_set(m1,m2);
    }
    for(int i=1;i<=p;i++)
    {
        cin>>p1>>p2;
        if(find_Set(p1)==find_Set(p2))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

}
void init_set(int n)//初始化集合，父节点设置为它本身
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
}
int find_Set(int x)//查找根节点
{
    if(fa[x]==x)
        return x;
    else
    {
        fa[x]=find_Set(fa[x]);
        return fa[x];
    }
}
void union_set(int x,int y)//合并
{
    x=find_Set(x);
    y=find_Set(y);
    fa[x]=y;
}