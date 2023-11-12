#include <bits/stdc++.h>
using namespace std;
int N, A, B;         // A:开始的层数：B：目标的层数
int floor_nums[202]; // 第N楼要移动的层数
int step = 0;
int bfs(int now_floor);
int main()
{
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        cin >> floor_nums[i];
    }
    int a = bfs(A);
    if (a == -1)
        cout << -1;
    if (a == 1)
        cout << step;
}
int bfs(int now_floor)
// 广度优先搜索，找最短的路径
{
    queue<int> floor;
    floor.push(now_floor);
    int head = now_floor;
    while (!floor.empty())
    {
        head = floor.front();
        if (head == B)
            return 1;
        if (head == A) // 回到了开始的层数
            return -1;
        floor.pop(); // 弹出第一个元素
        // int z=0;
        if (now_floor + floor_nums[now_floor] <= B)
        {
            floor.push(now_floor + floor_nums[now_floor]);
            step++;
        }
        if (now_floor - floor_nums[now_floor] >= 1)
        {
            floor.push(now_floor - floor_nums[now_floor]);
            step++;
        }
    }
}

/*
解题思路：要求最优解=>考虑BFS算法，广度优先
1,用目标楼层减现在楼层，得出要上还是下
2，先尝试以上的结果，不行则反着结果

*/