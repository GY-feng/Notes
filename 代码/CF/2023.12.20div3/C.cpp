#include <iostream>
#include <vector>
#include <algorithm>
/*
暴力最后一关的位置
为了到达第k关，需要用k次机会获得前面所有关卡的第一次收益
然后剩下K-k次机会全部刷前k关最高收益管卡
用前缀和预处理，时间复杂度O(N)
*/
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            std::cin >> b[i];
        }
        int res = 0, sum = 0, mx = 0;
        // 找到min然后开始叠加
        for (int i = 0; i < std::min(n, k); ++i)
        {
            sum += a[i];                                 // sum不会随着for循环而变小/不规律地变化，而是实现一个个地叠加
            mx = std::max(mx, b[i]);                     // 随着一个一个地迭代，一定能保持在最小的那个上面
            res = std::max(res, sum + mx * (k - i - 1)); // 随时更新
        }
        std::cout << res << std::endl;
    }
    return 0;
}
