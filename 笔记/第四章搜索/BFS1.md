#BFS
# 棋盘问题
```c++

#include<bits/stdc++.h>
using namespace std;
int Wx,Wy,num;//表示有Wx行，Wy列;用num统计可走的位置有多少
char room[23][23];
struct node//表示每个节点
{
        int x;
        int y;
};
int dir[4][2]={
{-1,0},//左（左上角的坐标为（0,0）
{0,-1},//上
{1,0},//右
{0,1}};//下
int main()
{
    int x,y, dx,dy;//dx和dy表示起点的坐标
    while(cin>>Wx>>Wy)
    {
        if(Wx==0&&Wy==0)
        {
            break;
        }
        for(y=0;y<Wy;y++)
        {
            for(x=0;x<Wx;x++)
            {
                cin>>room[x][y];
                if(room[x][y]=='@')//是起点呢
                {
                    dx=x;dy=y;
                }
            }
        }
    num=0;
    BFS(dx,dy);
    cout<<num<<endl;
    }
}
bool cheack_in_room(int x,int y)
{
    return x<Wx&&x>=0&&y>=0&&y<Wy;
}
void BFS(int dx,int dy)
{
    num=1;
    queue <node> q;
    node start,next;
    start.x=dx,start.y=dy;
    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();
    }
    for (int i = 0; i < 4; i++)//按照左上右下四个方向顺时针逐一搜索
    {
        next.x=start.x+dir[i][0];
        next.y=start.y+dir[i][1];
        if(cheack_in_room(next.x,next.y)&&room[next.x][next.y]=='.')
        {
            room[next.x][next.y]=='#';
            num++;
            q.push(next);
        }
    }    
}
```

# 八皇后问题
##八数码问题和状态图搜索
###问题：
        8个数字在3x3的棋盘当中，移动数码使得到达目标位置
        问到达某个指定位置时，要多少步
###分析：
        BFS，广度搜索
        但会发现需要判重，需要把新状态与9！对比，有9！*9！次检查
###判重方法：
        康拓展开：
        Cantor()复杂度：n^2
        输入一个排列，返回它的排名，在数组当中将其置为1，从而实现排列
        公式：第X个排序的计算公式如下：
        X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[2]*1+a[0]*0!
        a[i]表示原数的第i位在当前未出现的元素当中排在第几个（0开始）
    
```c++
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
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};//康拓展开需要用到的常数
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
    memcpy(head.state,start,sizeof(head.state));//复制起点的状态
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
            int nz=newx+3*newy;
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
    if(num!=1) cout<<num<<endl;
    else cout<<"Impossible"<<endl;
    int a=0;
    cin>>a;
    return 0;   
}

```
# 算法的优化

##BFS算法与A*算法：
    BFS是一种“盲目”的搜索技术，过程中并不理会目标在哪里
    A*属于一种“启发式搜索算法”简单而言，A*是BFS+贪心法

    程序如何知道向某个方向走最快？引入曼哈顿距离（两个点在坐标系上的实际距离（先上后下那种）
    从起点开始一圈，附近的点找到其曼哈顿距离，走曼哈顿距离更小的那样一个方向
##A*：
    用一个评估函数f（x）对情况进行评估，得到最好的状态，从这个状态继续搜索，找到最好的目标
    f(x)=g(x)+h(x)
    g(X)表示从初始状态到x的实际代价，不体现x和终点的实际关系
    h(X)表示x到终点的最优路径的评估（启发函数）h（x）决定了算法的优劣,h(x)不能漏掉最优解！

    八数码中,曼哈顿距离就是h(x).就是当前每一个数据到目标每一个数据的曼哈顿距离之和

##双向广搜：
    BFS增强版
    BFS想象成：在起点丢一块石头激起千层浪直到碰到终点，那么双向广搜就是在起点、终点同时做BFS
        两个波浪在某个位置相遇，就是最优路径了，这样比BFS的空间少很多，更有效
    应用地点：知道起点和终点，并且正向和逆向都能进行搜索

