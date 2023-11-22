#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const ll MAX_N=1000000009;
ll power[MAX_N];
vector<vector<int>>groups;//得到的是几个已经连续的数组了
vector<vector<int>>groupss;//得到的是几个已经连续的数组了

stack<int> s;
int maxnum=0;
int power[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> power[i];
    }
    sort(power + 1, power + 1 + n); // 从小到大排序
    for (int i = 1; i <= n; i++)    // 将排好序的数组一个个压入栈内
    {
        s.push(power[i]);
    }
    foreach (s);
    for(int i=0;i<groupss.size();i++)
    {
    get_group(groupss[i]);
    }
    vector<int> b = groups[0];
    int minlength = b.size();
    for (int i = 1; i < groups.size(); i++)
    {
        vector<int> c = groups[i];
        if (c.size() < minlength)
        {
            minlength = c.size();
        }
    }
    cout << minlength;
    cin>>n;

}
void get_group(vector<int> g)
{
    fill(power,power+n+1, 0);//置为0
    vector<int> thisgroup;
    vector<int> nextgroup;
    //int j=0;

    std::map<int, int> countMap;
    // 统计每个元素的出现次数
    for (int i = 0; i < g.size(); ++i) {
        countMap[g[i]]++;
    }

    // 找到出现次数最多的元素的下标
    int maxCount = 0;
    int maxIndex = -1;

    for (const auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxIndex = pair.first;
        }
    }
    if(maxCount!=1)
    {
        for(int i=0;i<=maxCount;i++)
        {
            thisgroup.push_back(g[i]);
        }
        for(int i=maxCount+1;i<g.size();i++)
        {
            nextgroup.push_back(g[i]);
        }
        groups.push_back(thisgroup);
        get_group(nextgroup);
    }
    else
    {
        //最大的出现次数为1，则返回整个vec即可
        groups.push_back(g);
        return ;
    }

    //std::cout << "出现次数最多的元素是 " << maxIndex << "，出现次数为 " << maxCount << " 次，下标为 ";
    // for (int i = 0; i < g.size(); i++)
    // {
    //     //j=g[i];
    //     power[g[i]]++;
    // }
    // int maxtimes=power[0];
    // for(int i=0;i<n;i++)
    // {
    //     if(power[i]>maxtimes)//找到最大的那个出现次数
    //     {
    //         maxtimes=power[i];
    //     }
    // }

    
}
void foreach (stack<int> s)
{
    if (s.empty()) // 传进来的栈s是空的（递归结束了）
    {
        return;
    }
    vector<int> con;
    int a = s.top();s.pop();
    con.push_back(a);
    while (!s.empty()) // 栈内有元素
    {
        int b = s.top();
        s.pop();
        if (b == a || a - b == 1)
        {
          // 清空原来的数组；
            con.push_back(b);
            a = b;
        }
        else
        {   groupss.push_back(con); // 把已经连续的这段加入
            con.clear(); 
            con.push_back(b);
            a = b;
        }
    }

}