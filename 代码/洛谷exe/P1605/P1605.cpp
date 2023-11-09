#include<bits/stdc++.h>
using namespace std;
vector<int>zhangai_x;
vector<int>zhangai_y;
int num=0;
int n,m,t,sx,sy,fx,fy;
int mat[6][6];
bool temp[6][6];//判断是否走过这个地方
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
//函数的声明：
bool check(int x,int y);
void dfs(int x,int y);

int main()
{
    ios::sync_with_stdio(false);//false即0,是C++的布尔值bool类型
    cin.tie(0); //0即空指针，可以写成C++的nullptr或C语言的NULL
    cout.tie(0);
    
    cin>>n>>m>>t;//长和宽
    cin>>sx>>sy>>fx>>fy;

    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=m;k++)
        {
            mat[i][k]=1;
        }
    }
   for (int i = 0; i <t; i++)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b]=0;
    }
    //采用：深度优先搜索
    dfs(sx,sy);
    cout<<num<<endl;
    int a=0;
    cin>>a;

}
bool check(int x,int y)
{
    if(temp[x][y]==0&&mat[x][y]==1)//没有走过，并且没有障碍捏
        return true;
    return false;
}
void dfs(int x,int y)
{
    if(x==fx&&y==fy)//走到终点了;
    {
        num++;
        return;
    }
    for(int i=0;i<=3;i++)
    {
        if(check(x+dx[i],y+dy[i]))
        {
            temp[x][y]=1;//走过了
            dfs(x+dx[i],y+dy[i]);
            temp[x][y]=0;//还原
        }
    }    
}