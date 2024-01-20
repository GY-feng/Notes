# DP算法：  
    简单解释：多阶段决策问题，将一个复杂的问题分解成相对简单的子问题，
    这些子问题前后相关，非常相似，处理方法几乎一样。
    将前问题的计算结果记录为“状态”，存储在“状态表”当中，后面的子问题查询状态表得知前面问题的答案，减少复杂度
## 一般思路：
    1，穷举法、暴力搜索穷举答案，画出递归树，尝试采用递归来进行求解
    2，如果发现存在大量的重复计算，记忆化搜索（哈希表缓存），遍历到相同的节点就直接查表
    3, 将计算的过程表示出来，观察计算的公式求解的顺序 ，尝试将递归形成改写成迭代形式（例如：两个for循环） 
## 区别于分治法：
    DP之间的问题是相关的，前面问题的解决结果可以被后面的子问题利用
## 适用：
    有重叠子问题和最优子结构性质的问题
## 步骤：
    1，定义状态
    2，状态转移
    3，算法实现
## 核心：状态、状态转移方程
    用状态转移方程求解状态，状态往往就是问题的解
## 分类：   
### 线性dp
    顺推和逆推，常用“表格”来处理状态，清晰地演示推导过程
### 非线性dp
    eg:树形dp
    两个方向：
        1，根->叶，传递有用的信息给子节点，最后根得出最优解
        2，叶->根，根的子节点传递有用的信息给根，最后根得最优解
# 基础dp:
## 7.1.1硬币问题：
### 最少硬币个数问题
```c++
#include<bits/stdc++.h>
using namespace std;
//最少硬币问题
const int MONEY=251;//最多金额
const int VALUE=5;//5种面值
int type[VALUE]={1,5,10,25,50};
int Min[MONEY];//每个金额对应的最少的硬币数量
void solve()
{
    for(int k=0;k<MONEY;k++)
        Min[k]=INT_MAX;
    Min[0]=0;
    for(int j=0;j<VALUE;j++)
        for(int i=type[j];i<MONEY;i++)
            Min[i]=min(Min[i],Min[i-type[j]]+1);
}//不断“优化”最优解，1个，5个，10个，25个...
int main()//打表的思路
{
    int s;
    solve();
    while(cin>>s)
    {
        cout<<Min[s]<<endl;
    }
    return 0;
}
```
### 打印最少硬币的组合：   
```c++
#include<bits/stdc++.h>
using namespace std;
//打印最少硬币的组合：要增加一个记录表Min_path[i]记录金额i所需的最后一个硬币，利用这个数组倒推就能得到所有的硬币

const int MONEY=251;//最多金额
const int VALUE=5;//5种面值
int type[VALUE]={1,5,10,25,50};
int Min[MONEY];//每个金额对应的最少的硬币数量
int Min_path[MONEY]={0};//记录最小硬币的路径
void solve()
{
    for(int k=0;k<MONEY;k++)
        Min[k]=INT_MAX;
    Min[0]=0;
    for(int j=0;j<VALUE;j++)
        for(int i=type[j];i<MONEY;i++)
            if(Min[i]>Min[i-type[j]]+1)
            {
                Min_path[i]=type[i];//在每个金额上记录路径，即某个硬币的面值
                Min[i]=min(Min[i],Min[i-type[j]]+1);
            }
}//不断“优化”最优解，1个，5个，10个，25个...
void print_ans(int *Min_path,int s )
{
    while(s)
    {
        cout<<Min_path[s]<<" ";
        s=s-Min_path[s];
    }
}
int main()//打表的思路
{
    int s;
    solve();
    while(cin>>s)
    {
        cout<<Min[s]<<endl;
    }
    return 0;
}
``` 
### 所有的硬币组合个数：
```c++
#include<bits/stdc++.h>
using namespace std;
const int COIN=101;//硬币的最大个数
const int MONEY=251;//最大金额
int dp[MONEY][COIN]={0};
int type[5]={1,5,10,20,50};
void solve()
{
    dp[0][0] = 1;
    for (int i = 0; i < 5; i++)//枚举5种硬币
    {
        for (int j = 1; j<COIN;j++)//硬币的个数没有达到上限,这里从1个硬币开始枚举
        {
            for (int k = type[i]; k < MONEY; k++)
            {
                dp[k][j]+=dp[k-type[i]][j-1];//转移矩阵+=dp[待求金额-面值][硬币个数-1]；
            }
            
        }
    }
}
int main()
{
    int s;
    int ans[MONEY]={0};
    solve();//计算状态转移矩阵
    for(int i=0;i<MONEY;i++)
    {
        for (int j = 0; j < COIN; j++)//打表计算每个金额有多少种组合方案
        {
            ans[i]+=dp[i][j];//从0开始计算
        }
        while(cin>>s)
        {
            cout<<ans[s]<<endl;
        }
        
    }
}
```