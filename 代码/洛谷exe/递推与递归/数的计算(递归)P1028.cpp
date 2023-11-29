#include<bits/stdc++.h>
/*
8后面加上一个元素，可以是4/3/2/1
但要加上其他的数列，怎么处理？=>
加上4/3/2/1的答案即可
原本是8的问题，现在分解成了4个子问题的问题，一直向下分解，直到得到了解为止。直到1，无法再继续分解即可
*/
int f[1010],n;
using namespace std;
int solution_vision2(int x);
int main()
{
    cin>>n;
    memset(f,-1,sizeof(f));//将f中的每一个元素的值都赋值成-1
    f[1]=1;
    int k=solution_vision2(n);
    cout<<k;
}
/*
solution不能通过问题，原因是做了很多的无效功，比如sol(2)会被sol(4)和sol(8)重复计算
所以可以定义一个数组f，当需要问题的答案是，进行查询
*/
int solution_vision2(int x)
{
    int ans=1;
    if(f[x]!=-1)
    {
        return f[x];
    }
    for (int i = 1; i <= x/2; i++)
    {
        ans+=solution_vision2(i);
    }
    return f[x]=ans;//将 ans 赋值给数组 f 的第 x 个元素，并将这个值作为函数的返回值返回。
}
int solution_vision1(int x)
{
    if (x==1)
    {
        return 1;
    }
    int ans=1;//自己本身就是一个解
    for (int i = 1; i <= x/2; i++)
    {
        ans+=solution_vision1(i);
    }
    return ans;
}