/*
有n个不同颜色的弹珠
A有a1个颜色为1，a2个颜色为2，a3个颜色为3...
B有b1个颜色1，b2个颜色2,a3个颜色为3...
ai和bi在1到10^9
A先开始，轮流，在回合中，一个玩家选择一个颜色i（双方玩家都至少有这个颜色的一颗弹珠）
然后，该玩家弃掉一颗这个颜色的珠子，而对手弃掉所有颜色为i的珠子。
当没有颜色i且双方玩家都至少有一颗该颜色的弹珠时，游戏结束
分数：A和B剩下的弹珠之差(A-B就行，不用abs),游戏中A想要分数最大，而B想要分数最小
两个玩家按照他们想的最优方案计算分数
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int n=0,tmp=0;
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        b.push_back(tmp);
    }
}