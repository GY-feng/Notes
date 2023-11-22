#include<bits/stdc++.h>
using namespace std;
#define int long long//开ll防止见祖宗
int n;
int power[100005];
int minlength=1000000;
//vector<int> power;
vector<vector<int>> groups;
stack<int>s;
stack<stack<int>>ss;
//函数声明
void foreach(stack<int>s);
signed main()
{
    cin>>n;
    //int a=0;
    for(int i=1;i<=n;i++)
    {
        //cin>>a;
        //power.push_back(a);
        cin>>power[i];
    }
    sort(power+1,power+1+n);//从小到大排序
    for(int i=1;i<=n;i++)//将排好序的数组一个个压入栈内
    {
        s.push(power[i]);
    }
    foreach(s);
    vector<int>b=groups[0];
    minlength=b.size();
    for(int i=1;i<groups.size();i++)
    {
        vector<int>c=groups[i];
        if(c.size()<minlength)
        {
            minlength=c.size();
        }
    }
    cout<<minlength;
    cin>>n;
    return 0;
}
void foreach(stack<int>s)
{
    if(s.empty())//传进来的栈s是空的（递归结束了）
    {
        return;
    }
    vector<int> con;
    stack<int> uncon;
    int a=s.top();s.pop();
    con.push_back(a);
    while(!s.empty())//栈内有元素
    {
        int b=s.top();s.pop();
        if(b==a)
        {
            uncon.push(b);
        }
        else
        {
            if(a-b!=1)
            {
                groups.push_back(con);//把已经连续的这段加入
                con.clear();//清空原来的数组；
                con.push_back(b);
                a=b;
            }
            else
            {
                con.push_back(b);
                a=b;
            }
        }

    }
    groups.push_back(con);//讲分好的组保存下来
    stack<int> aaa;int ccc=0;
    while(!uncon.empty())
    {
        ccc=uncon.top();uncon.pop();
        aaa.push(ccc);
    }
    foreach(aaa);
}
