#include<bits/stdc++.h>
using namespace std;
int n,total;
int chess[14][14];
int col[14]={0};
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            chess[i][k]=1;
        }    
    }   
}
bool check(int r,int c)
{
    for (int i = 0; i < n; i++)
    {
        if(col[i]==c||(abs(col[r]-c)==abs(i-r)))//判断所在的列是否等
        {
            return false;
        }
        
    }
    
}
void search(int r)//深度优先搜索,参数ri表示在第几行
{
    if (r==n)//摆放完毕
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
                col[r]=i;//在r行的c列放置皇后
                search(r+1);
            }
        }
    }

}