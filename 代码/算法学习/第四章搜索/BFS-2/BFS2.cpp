#include<bits/stdc++.h>
using namespace std;

const int LEN=362880;
struct node
{
    int state[9];//记录八数码的排列，一个状态
    int distance;//记录到起点的距离
};
int visited[LEN]={0};//原先的状态全为0
int start[9];//开始目标
int goal[9];//结束目标
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};//康拓展开需要用到的常数，打表以减少空间
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
//康托展开
bool Cantor(int str[],int n)
{
    int result=0;
    for (int i = 0; i < n; i++)
    {
        int counted=0;
        for (int j = i+1; j < n; j++)
        {
            if(str[i]>str[j])//当前未出现的元素排在第几个
                ++counted;

        }
        result+=counted*factory[n-i-1];//用数组枚举
    }
    if(!visited[result])//没有被访问过
    {
        visited[result]=1;
        return 1;
    }
    else
        return 0;
    
}
int BFS()
{
    node head;
    memcpy(head.state,start,sizeof(head.state));
    //复制起点的状态，从start当中拷贝sizeof(head.state)个字符到head.state当中
    head.distance=0;
    queue<node>q;
    Cantor(head.state,9);
    q.push(head);

    while (!q.empty())
    {
        head=q.front();
        if(memcmp(head.state,goal,sizeof(goal))==0)//与目标状态对比
        {
            return head.distance;//到达目标目标，返回局里，结束
        }
        q.pop();
        int z;
        for ( z = 0; z <9; z++)
        {
            if(head.state[z]==0)
                break;
        }
        //转化为二维，左上角是原点(0,0)
        int x=z%3;//横坐标
        int y=z/3;//纵坐标
        for (int i = 0; i < 4; i++)//上下左右最多可能有4个新状态
        {
            //元素0转移后的新坐标
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            //转化成1维
            int nz=newx+3*newy;//Why?

            
            if(newx>=0&&newx<3&&newy>=0&&newy<3)
            {
                node newnode;
                memcpy(&newnode,&head,sizeof(struct node));
                swap(newnode.state[z],newnode.state[nz]);//0移动到新的位置
                newnode.distance++;
                if (Cantor(newnode.state,9))
                {
                    q.push(newnode);
                }
                
            }
            
        }
        
    }
    return -1;

}
    //八数码问题和状态图搜索
    /*问题：
        8个数字在3x3的棋盘当中，移动数码使得到达目标位置
        问到达某个指定位置时，要多少步
    分析：
        BFS，广度搜索
        但会发现需要判重，需要把新状态与9！对比，有9！*9！次检查
    判重方法：
        康拓展开：
        Cantor()复杂度：n^2
        输入一个排列，返回它的排名，在数组当中将其置为1，从而实现排列
        公式：第X个排序的计算公式如下：
        X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[2]*1+a[0]*0!
        a[i]表示原数的第i位在当前未出现的元素当中排在第几个（0开始）
    */
int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin>>start[i];
    }
    for (int i = 0; i < 9; i++)
    {
        cin>>goal[i];
    }
    int num=BFS();
    if(num!=-1) cout<<num<<endl;
    else cout<<"Impossible"<<endl;
    int a=0;
    cin>>a;
    return 0;   
}
