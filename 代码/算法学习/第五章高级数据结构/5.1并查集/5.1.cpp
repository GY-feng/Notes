#include<bits/stdc++.h>
using namespace std;
const int maxn=1050;
int s[maxn+1];//用s存储每个元素的父节点s[i]=j代表着i的父节点是j
int height[maxn+1];//合并的优化时候使用
void init_set()//初始化集合，开始的时候，将父节点设置为自己
{
    for (int i =1; i <=maxn; i++)
    {
        s[i]=i;
        height[i]=0;//树的高度
    }
}
int find_Set(int x)//查找,(已经进行了路径优化)
{
    if (s[x]==x)
    {
        return x;
    }
    else//优化,eg:在查找4的时候，将4的父节点设置为1而不再是3，3的父节点设置为1，减少查询次数（并查集必须写！！！）

    {
        s[x]=find_Set(s[x]);
        return s[x];
    }
    //return x==s[x]?x:find_Set(s[x]);
}
int find_set_without_stack(int x)//上面的代码采用栈的方式实现，如果怕栈爆掉，采用以下的方式：
{
    int root =x;
    while(s[root]!=root)root=s[root];//查找根节点
    int i=x,j;
    while(i!=root)
    {
        j=s[i];//临时变量记录
        s[i]=root;//把路径上的元素的集改为根节点
        i=j;
    }
    return root;
}
void union_set(int x,int y)//合并
{
    x=find_Set(x);//找到x,y的祖先
    y=find_Set(y);
    //if(x!=y)s[x]=s[y];//    i的祖先指向j的祖先
 //合并操作的优化：将高度较小的集合合并到大的集合上，以减少树的高度，
    if(height[x]==height[y])
    {
        height[x]=height[y]+1;//合并，树的高度加一
        s[y]=x;//祖先移动
    }
    else
    {
        if(height[x]<height[y])
        {
            s[x]=y;
        }
        else
        {
            s[y]=x;
        }

    }
}
int main()
{
    int t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init_set();
        for (int i = 1; i <=n; i++)
        {
            cin>>x>>y;
            union_set(x,y);
        }
        
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==i)
        ans++;
    }
    cout<<ans<<endl;
}
//合并的优化：
int height[maxn+1];
void union_set_pro(int x,int y)//合并
{
    x=find_Set(x);
    y=find_Set(y);
    if(x!=y)s[x]=s[y];
}