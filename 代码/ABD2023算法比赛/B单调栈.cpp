#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1e5 + 3
int n;
int f[100003];
stack<int> st;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    st.push(f[0]);
    cout << "-1"
         << " ";
    for (int i = 1; i < n; i++)
    {
            if (!st.empty() && st.top() < f[i]) // 栈不为空或者即将入栈的元素大于栈第一个
            {
                cout << st.top() << " ";
                st.push(f[i]); // 元素入栈
            }
            else
            {
                vector<int> aaa;
                aaa.push_back(f[i]);
                while (!st.empty() && st.top() > f[i])
                {
                    aaa.push_back(st.top());
                    st.pop();
                }
                if(st.empty())//栈全空了，说明都不满足
                {
                    cout<<"-1"<<" ";
                }
                else{
                    cout<<st.top();
                }
                for(int i=aaa.size();i>=0;i--)
                {
                    st.push(aaa[i]);//加回去栈里面
                }
            }
    }
    cin>>n;
}