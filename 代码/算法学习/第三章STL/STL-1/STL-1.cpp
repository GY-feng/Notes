#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 10;
// 数组的使用：
/*
对于竞赛而言，能使用静态数组则静态数组，空间紧张可以用STL开动态，节约空间，不易出错
*/
vector<int> a(100);                   // 定义100个值为0的元素
vector<string> b(100, "null");        // 十个值为null的元素
vector<string> c(b.begin(), b.end()); // c是b的复制
vector<int> d[MAXN];                  // 定义一个二维数组，它的一维大小是固定的MAXN，二维动态（实现图的邻接表存储）
// vector的索引在常数级别，但是插入和删除速度很慢（要复制内存块）所以少用

// stack的使用：
stack<int> a_stack;

// 队列和queue:
queue<int> q;

// 优先队列priority_queue:
priority_queue<int> pq;
// 优先级别高的元素先出列
// 可以排序，复杂度：nlog2n

// 链表和list:
// list：双向链表，高效地删除和插入
list<int> l;
list<int>::iterator it;

// set集合
// 使用二叉搜索树实现，元素只出现一次，并且是排好序的，
//访问的时间复杂度是log2n
set<int> s;

// map
// map可以实现快速查照，复杂度log2n
map<string, int> m;

// 函数的声明：
void soilder();
int main()
{

    soilder();
    int a = 0;
    cin >> a;
}

// 士兵报数问题：
void soilder()
{
    int t, n;
    cin >> t;
    int k = 3;
    while (t--)
    {
        cin >> n;
        list<int> l_soilder;
        list<int>::iterator it;
        for (int i = 1; i <= n; i++)
            l_soilder.push_back(i);
        while (l_soilder.size() > 3)
        {
            int num = 1;
            if (k == 3)
                k = 2;
            if (k == 2)
                k = 3;
            for (it = l_soilder.begin(); it != l_soilder.end();)
            {
                num++;
                if (num % k == 0)
                {
                    it = l_soilder.erase(it); // 删除后it也会++
                }
                else
                {
                    it++;
                }
            }
        }
        for (it = l_soilder.begin(); it != l_soilder.end(); it++)
        {
            cout << *it;
            cout << " ";
        }
        cout << endl;
    }
}
// 约瑟夫问题
void Table()
{
    vector<int> table;
    int n, m;
    while (cin >> n >> m)
    {
        table.clear(); // 清空上次的数据
        for (int i = 0; i < 2 * n; i++)
        {
            table.push_back(i);
        }
        int pos = 0; // 记录下标元素
        for (int i = 0; i < n; i++)
        {
            // 赶走n个人
            pos = (pos + m - 1) % table.size(); // 因为从当前下标开始数起，并且为了不超过，所以进行取余操作
            table.erase(table.begin() + pos);   // 赶走坏人，长度-1
            // 此次的erase执行的速度较慢，少用！
        }
        for (int i = 0, j = 0; i < 2 * n; i++)
        {
            if (j < table.size() && i == table[i]) // 剩下来的都是好人
            {
                j++;
                cout << "G";
            }
            else
            {
                cout << "B";
            }
        }
        cout << endl;
    }
}