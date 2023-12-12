#include <bits/stdc++.h>
using namespace std;
int n;
int mat[15][15];
vector<vector<int>> groups;
int total;
int main()
{
    cin>>n;
}
bool check(int x,int y)
{
    if(x>n||y>n)
        return false;
    if()
}
void dfs(int r)
{
    if(r==n)
    {
        total++;
        return;
    }
else
{
    for (int i = 0; i < n; i++)
    {
        if(check(r,i))//第r行
        {
            mat[r]=i;//r行c列放皇后
            dfs(r+1);
        }
    }
    
}
}
/*
模板：
```c++
这里还有两个普通的深搜模板
深度优先搜索算法框架1
int Search(int k)
　{
　for (i=1;i<=算符种数;i++)
　　if (满足条件)
　　   {
　　　　保存结果
　　　　if (到目的地) 输出解;
　　　           else Search(k+1);
　　　　恢复：保存结果之前的状态{回溯一步}
　 　  }
　}
 深度优先搜索算法框架2
int Search(int k)
　{
　  if  (到目的地) 输出解;
　　　else
　　　　for (i=1;i<=算符种数;i++)
　　　　　if  (满足条件) 
　　　　　　　{
　　　　　　　　保存结果;
　　　                  Search(k+1)
                             恢复：保存结果之前的状态{回溯一步}
　　　　　　　}
　}
 希望各位都能顺利学会DFS，也希望管理大大能通过此篇题解！
```
*/