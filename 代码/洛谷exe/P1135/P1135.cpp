#include<bits/stdc++.h>
using namespace std;
int N,A,B;
int floor_nums[202];
int main()
{
    cin>>N>>A>>B;

}
void bfs(int now_floor,int aim_floor)
{
    if(now_floor==aim_floor)
        return;
    queue<int> floor;
    
}
bool check(bool a,int now ,int floor)//3个参数,a代表上下，1上0下，now代表现在的楼层,floor代表要去到什么楼层
{
    if(a==true)//要上
    {
        if(now+floor>N)
            return false;
        else
            return true;
    }
    if(a==false)//要下
    {
        if(now-floor<1)
            return false;
        else
            return true;
    }  
}
/*
解题思路：要求最优解=>考虑BFS算法，广度优先
1,用目标楼层减现在楼层，得出要上还是下
2，先尝试以上的结果，不行则反着结果

*/