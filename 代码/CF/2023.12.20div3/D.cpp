#include <bits/stdc++.h>
using namespace std;
/*
思路：分别在3个数组中找到每个数组的3个较大值,保存到一对pair当中
通过排列组合的方式，当元素的下标不是一样的时候，A33即可找到最大的值
*/
void solve();
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    cin>>t;
}
void solve()
{
    int day = 0;
    cin >> day; // 寒假的天数
    vector<int> a(day), b(day), c(day);vector<pair<int,int>> a_max, b_max, c_max;//第一个int代表值，第二个代表坐标
    for (int i = 0; i < day; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < day; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < day; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < 3; i++)
    {
        auto maxelea = max_element(a.begin(), a.end());
        auto maxeleb = max_element(b.begin(), b.end());
        auto maxelec = max_element(c.begin(), c.end());

        if (maxelea != a.end())
        {
            // 使用 std::distance 获取迭代器相对于 vector 起始位置的下标
            int index = std::distance(a.begin(), maxelea);
            a_max.push_back(make_pair(*maxelea,index));
            *maxelea = -1;
        }
        if (maxeleb != b.end())
        {            
            int index = std::distance(b.begin(), maxeleb);
            b_max.push_back(make_pair(*maxeleb,index));
            *maxeleb = -1;
        }
        if (maxelec != c.end())
        {
            int index = std::distance(c.begin(), maxelec);
            c_max.push_back(make_pair(*maxelec,index));
            *maxelec = -1;
        }
    }
    int maxnum=0,tmp=0;
    for (int i = 0; i < 3; i++)
    {
        for (int g = 0; g < 3; g++)
        {
            for (int k = 0; k < 3; k++)
            {
                if(a_max[i].second!=b_max[g].second&&a_max[i].second!=c_max[k].second&&b_max[g].second!=c_max[k].second)
                {
                tmp=a_max[i].first+b_max[g].first+c_max[k].first;
                maxnum=max(maxnum,tmp);
                }
            }
        }
    }
    cout<<maxnum<<endl;
}