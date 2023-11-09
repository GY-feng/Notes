#include<bits/stdc++.h>
using namespace std;
int n,tot=0;
int col[12]={0};
/*
    DFS:深度优先搜索
    回溯与剪枝：
        回溯：递归的时候“看到不对头就撤退”的思想，返回。
        其中，用于减少子节点扩展的函数就叫做剪枝函数
        八皇后问题：    
            棋盘上放8皇后，使他不同行列对角线
            回溯与剪枝：设已经放好的皇后坐标（i,j）新皇后坐标（r，c）
                则：列不同(j不等于c)对角线不同（若同，则有左上，左下，右上，右下关系综合而言就是不可以|i-r|==|j-c|

*/
bool check(int c,int r )
{
    for (int i = 0; i < r; i++)
    {
        if(col[i]==c||(abs(col[i]-c)==abs(i-r)))//检查列，对角线是否有其他皇后
            return false;
    }
    return true;    
}
void DFS(int r )//一行一行地放皇后，这次是第r行
{
    if(r==n)//所有的皇后都放置好了，返回
    {
        tot++;//统计合法的棋盘个数
        return ;
    }
    for (int c = 0; c < n; c++)//在对应行的某一列放皇后
    {
        if(check(c,r))//检查合法性
        {
            col[r]=c;//在第r行的c列放皇后
            DFS(r+1);//准备在下一行放皇后
        }
    }
    
}
int main()
{
    //auto start_time = std::chrono::high_resolution_clock::now();
    int ans[12]={0};
    for(n=0;n<=10;n++)//先打表计算皇后问题
    {
        memset(col,0,sizeof(col));//清空，准备下一个八皇后类型
        tot=0;
        DFS(0);//此处代表第0行
        ans[n]=tot;//打表
    }
    while(cin>>n)
    {
        if(n==0)
        return 0;
        cout<<ans[n]<<endl;
    }
    //auto end_time = std::chrono::high_resolution_clock::now();
    // 计算执行时间间隔
    //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // 输出执行时间
    // std::cout << "程序执行时间: " << duration.count()/1000 << " 秒" << std::endl;
    return 0;
}