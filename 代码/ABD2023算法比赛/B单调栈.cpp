#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// ProblemB
int main()
{
    int n = 0;
    cin >> n;
    int numbers[100005],res[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && numbers[i] <= s.top()) // 栈不为空并且遍历到的元素比栈顶（比遍历到的数还要先入栈）还小
        {
            s.pop();
        }
        s.empty() ? res[i]=-1:res[i]= s.top();
        s.push(numbers[i]);
    }
    for (int i = 0; i < n; i++)
    {
            cout<<res[i]<<' ';
    }
    cin>>n;
}