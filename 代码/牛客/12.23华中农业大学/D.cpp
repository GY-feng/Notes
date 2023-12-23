#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n = 0; // n为奇数，代表博弈场次
// vector<int> match;
vector<pair<int, int>> match; //<代价值,场次>
const int MAX_N = 1000000005;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = n - ((n + 1) / 2) + 1, aaa;
    for (int i = 1; i <= n; i++)
    {
        cin >> aaa;
        match.push_back(make_pair(aaa, i)); // 按照键-对插入到vector当中
    }
    sort(match.begin(), match.end(), cmp);
    vector<int> vec_ans;
    int t = 0;
    for (int i = 0; i < ans; i++)
    {
        vec_ans.push_back(match[i].second); // 将下标插入
        t += match[i].first;
    }
    sort(vec_ans.begin(), vec_ans.end()); // 下标排序
    cout << t << endl;                    // 输出最小代价
    for (auto v : vec_ans)                // 输出下标
    {
        cout << v << " ";
    }
}