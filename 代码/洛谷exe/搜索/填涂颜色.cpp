/*
思路：
1，现在所有数字周围先围一圈0，然后按照右、下的方法，将那一圈0改成5
2，遍历矩阵，将0设置成2
3，再次遍历，将3设置成0
//虽然这个代码过不了，但是主要到要在所有的数字外面加一圈0再进行搜索是很好的思想
*/
#include<bits/stdc++.h>
using namespace std;
int n=0;
int mat[35][35];
void dfs(int x,int y);
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            cin>>mat[i][k];
        }
    }
    dfs(0,0);
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if(mat[i][k]==3)
            {
                cout<<0;
            }
            if(mat[i][k]==1)
            {
                cout<<1;
            }
            if(mat[i][k]==0)
            {
                cout<<0;
            }
        } 
        cout<<endl;   
    }
    
}
void dfs(int x,int y)
{
    //向右和向下分别搜索
    if(mat[x][y]==0)
    {
        mat[x][y]=3;
        if(x+1<=n+1&&y<=n+1)
        {
            dfs(x+1,y);
        }
        if(x<=n+1&&y+1<=n+1)
        {
            dfs(x,y+1);
        }
    }
}
