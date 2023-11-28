// n个小球按顺序一个个入管，
// 一次可以任意个球倒出来，求倒出来的方式：
/*
分析：
    每一个球都可以是最后出管的
    设第k个球是最后出管的，比k早入且早出有k-1
    共h[k-1]种方式，比k晚入早出有n-k,共h[n-k]方式
    则这种情况下有h[k-1]*h[n-k]方式
    所以递推式：
    h(n)=h(0)*h(n-1)+h(1)*h(n-2)+...+h(n-1)*h(0)
    h[0]=h[1]=1

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h[20] = {1, 1};
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            h[i] += h[j] * h[i - j - 1];
        }
    }
    cout << h[n];
}