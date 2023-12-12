# DFS

## DFS:深度优先搜索
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
例题：单词输出：
```C++
#include <iostream>
#include <algorithm>
using namespace std;
// P1101单词方阵
char word[] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
char mat[103][103];
char ansmat[103][103];
int n;
void dfs(int dr, int dc, int r, int c, int cut);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            cin >> mat[i][k];
            ansmat[i][k] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (mat[i][k] == 'y')
            {
                // 这里是起点了哇
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (mat[i + dr][k + dc] == 'i')
                        {
                            dfs(dr, dc, i, k, 0); // 方向，搜索
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (ansmat[i][k])
            {
                cout << mat[i][k];
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
// dr,dc是方向，r，c代表第一个字母'r'的坐标位置
void dfs(int dr, int dc, int r, int c, int cut)
{
    if (cut == 7)
    {
        for (int i = 1; i <= 7; i++)
        {
            ansmat[r - dr * i][c - dc * i] = 1; // 标记为保留
        }
    }
    if (r >= 1 && r <= n && c >= 1 && c <= n && mat[r][c] == word[cut])
    {
        dfs(dr, dc, r + dr, c + dc, cut + 1);
    }
    return;
}

```
例题：自然数的拆分：
```c++
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int a[10001] = {1}, n;
////用于存储拆分 n 的数的序列。初始值为 1，因为 a[0] 是用于开始拆分的初始值。

void search(int, int);
void print(int);
int main()
{
    cin >> n;
    search(n, 1); // 将要拆分的数n传递给s
    return 0;
}
void printff(int t)
{
    for (int i = 1; i <= t - 1; i++) // 输出一种拆分方案  [9934] 0 int

        cout << a[i] << "+";
    // if(a[t]!=t)
    cout << a[t] << endl;
}

void search(int s, int t) // s是要拆分的数值，t是要拆分的位数
{
    int i;
    for (i = a[t - 1]; i <= s; i++)
        if (i < n) // 当前数i要大于等于前一位数，且不超过n
        {
            a[t] = i; // 保存当前拆分的数i
            s -= i;   // s减去数i，s的值将继续拆分
            if (s == 0)
                printff(t); // 当s=0时，拆分结束输出结果
            else
                search(s, t + 1); // 当s>0时，继续递归
            s += i;               // 回溯，加上拆分的数(回复s开始的值)，使得产生所有可能的拆分
        }
}
```
例题3：
```c++
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
```
## 总结BFS，DFS

    设点的数量是V连接点的边的总数是E，那么总复杂度是O（V+E）但是有些V和E本身就是指数级的
    因此搜索的时候多用剪枝、回溯、双向广搜、迭代加深、A*、IDA*等方法去加上你好搜索的次数

    应用场合：
    能用DFS，尽量使用。
    BFS：求解最优解（如迷宫这样的求最短路径）
    DFS：多用于求可行解
