# DFS

## DFS:深度优先搜索

### 回溯与剪枝

    回溯：递归的时候“看到不对头就撤退”的思想，返回。
    其中，用于减少子节点扩展的函数就叫做剪枝函数
####八皇后问题：
    棋盘上放8皇后，使他不同行列对角线
    回溯与剪枝：设已经放好的皇后坐标（i,j）新皇后坐标（r，c）
    则：列不同(j不等于c)对角线不同（若同，则有左上，左下，右上，右下关系综合而言就是不可以|i-r|==|j-c|
```c++
# include<bits/stdc++.h>
using namespace std;
int n,tot=0;
int col[12]={0};
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

    return 0;
}
```
## IDDFS
    迭代加深搜索：IDDFS
        某些题目，很深很广，DFS陷入递归无法返回，BFS队列空间爆炸
        操作：
            1，先设置搜索深度为1，用DFS搜索到第一层就停止（DFS搜索一个深度为1的搜索树）
            2，没有找到答案，那么就再设定搜索深度为2，用DFS搜索前两层就停止（DFS搜索一个深度为2的搜索树）
            3，继续设定深度为3/4，逐步扩大范围，找到答案，
            过程当中，每一层在广度上采用了BFS的思想，编程实现上则是DFS的
    IDA*：对IDDFS的优化
        IDDFS实际上仍然是一种“盲目”的搜索，只是把范围控制在了可行的空间当中，如果能在IDDFS的过程当中预测当前DFS的状态，不再深入，就可以提高效率，这个预测就是在IDDFS当中加一个估价函数（经过这个函数计算，发现后续无解，则返回）
        简单而言，就是在过程当中利用估价函数进行剪枝操作

eg：从1开始，要进行多少次加减法才能到达n
```c++

# include<bits/stdc++.h>
using namespace std;
int val[1010];
int pos,n;

bool ida(int now,int depth)
{
    if(now>depth)
        return false;//IDDFS大于当前设置的深度
    if(val[pos]<<(depth-now)<n)
        return false;//估价函数，用最快的速率都不能到达n，退出
    if(val[pos]==n)return true;
    pos++;
    for (int i = 0; i < pos; i++)
    {
        val[pos]=val[pos-1]+val[i];//上一个数与前面所有的数相加
        if(ida(now+1,depth)) return true;//
        val[pos]=abs(val[pos-1]-val[i]);//上一个数与前面的所有数相减
        if(ida(now+1,depth))return true;
    }
    pos--;
    return false;
}

int main()
{
    while (cin>>n&&n)
    {
        int depth;
        for (depth =0;;depth++)//每次只DFS到深度depth
        {
            val[pos=0]=1;//初始值是1
            if(ida(0,depth))
                break;
        }
        cout<<depth<<endl;
    }
}


```

## 总结BFS，DFS

    设点的数量是V连接点的边的总数是E，那么总复杂度是O（V+E）但是有些V和E本身就是指数级的
    因此搜索的时候多用剪枝、回溯、双向广搜、迭代加深、A*、IDA*等方法去加上你好搜索的次数

    应用场合：
    能用DFS，尽量使用。
    BFS：求解最优解（如迷宫这样的求最短路径）
    DFS：多用于求可行解
