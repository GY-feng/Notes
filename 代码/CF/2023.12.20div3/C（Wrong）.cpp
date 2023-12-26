#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t; // t个测试用例
int MaxTotal_in_b(vector<int> b, int bbegin_pos, int bend_pos, int times);
int add(vector<int> a, int abegin_pos, int aend_pos, vector<int> b, int bbegin_pos, int bend_pos, int times);
void solve();
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
/*
暴力最后一关的位置
为了到达第k关，需要用k次机会获得前面所有关卡的第一次收益
然后剩下K-k次机会全部刷前k关最高收益管卡
用前缀和预处理，时间复杂度O(N)
*/
void solve()
{
    int n = 0, k = 0, tmp = 0;
    cin >> n >> k; // n代表着任务的数量,k代表着能做的最多的任务
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    int exp = 0;
    if (k >= n) // 能将n个任务都完成一遍
    {
        for (int i = n; i >= 1; i--) // 将每个任务都过一次
        {
            int aaa = 0;
            int restTask = k - i; // 剩余能做的任务的最大
            for (int k = 0; k < i; k++)
            {
                aaa += a[k];
            }
            aaa += MaxTotal_in_b(b, 0, i, restTask);
            exp = max(exp, aaa);
        }
        cout << exp << endl;
    }
    else // 不能将n个任务全部完成一次
    {
        for (int i = k; i >= 1; i--) // i:最多推进的任务数
        {
            exp = max(exp, add(a, 0, i - 1, b, 0, i - 1, k - i));
        }
        cout << exp << endl;
    }
}
int add(vector<int> a, int abegin_pos, int aend_pos, vector<int> b, int bbegin_pos, int bend_pos, int times)
{
    int c = 0;
    for (int i = abegin_pos; i <= aend_pos; i++)
    {
        c += a[i];
    }
    // 将下标转化为迭代器
    // int index = 3;  // 你要访问的元素的下标

    auto itb_begin = std::next(b.begin(), bbegin_pos);
    auto itb_end = std::next(b.begin(), bend_pos);
    // next 函数接受一个迭代器和一个偏移量，并返回指向偏移后位置的新迭代器。
    auto max_in_b = max_element(itb_begin, itb_end); // 返回迭代器
    int Max = *max_in_b;
    c += Max * times;
    return c;
}
int MaxTotal_in_b(vector<int> b, int bbegin_pos, int bend_pos, int times)
{
    auto itb_begin = std::next(b.begin(), bbegin_pos);
    auto itb_end = std::next(b.begin(), bend_pos);
    // next 函数接受一个迭代器和一个偏移量，并返回指向偏移后位置的新迭代器。
    auto max_in_b = max_element(itb_begin, itb_end); // 返回迭代器
    int Max = *max_in_b;
    return Max * times;
}