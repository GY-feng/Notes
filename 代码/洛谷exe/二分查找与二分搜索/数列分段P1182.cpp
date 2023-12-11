#include <iostream>
#include <algorithm>
using namespace std;
int n, m; // n:数列的长度，m:要分成的段数
int sequence[100005];
const int MAX_N = 1e9 + 4;
int Find(int L, int R); // 使用前确保答案在[L,R]内//注意，开始的L=0，数组从第1位开始放数字捏

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> sequence[i];
    }
    int maxn = Find(1, MAX_N);
    cout << maxn;
}
bool P(int x) // 判断函数
{
    int k = 0;     // 需要的段数
    int total = 0; // 每一段开头的总计和
    for (int i = 1; i <= n; i++)
    {
        if (total + sequence[i] <= x)
        {
            total += sequence[i];
            if (i == n) // 最后一个数字
            {
                k++; // 加上最后一段捏
            }
        }
        else
        {
            if (sequence[i] > x)
            {
                return false; // 数组当中的这个数字都比传进来的x要大，那么直接退了就行
            }
            k++;
            total = 0;
            total += sequence[i];
            if (i == n) // 最后一个数字
            {
                k++; // 加上最后一段捏
            }
        }
    }
    if (k > m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Find(int L, int R) // 使用前确保答案在[L,R]内//注意，开始的L=0，数组从第1位开始放数字捏
{
    int ans, mid;
    while (L <= R) // 闭区间上的二分条件
    {
        // if (R ==6)
        //{
        //     cout << "R<=100";
        // }
        int mid = L + R >> 1;
        if (P(mid)) // 条件成立
        {
            ans = mid;
            R = mid - 1;
        }
        // 只需要记录满足条件的mid，最后循环一定会结束，也一定会在ans当中保留正确的答案
        else
            L = mid + 1; // L和R不用考虑+1和-1，全部写上去
    }
    return ans;
}