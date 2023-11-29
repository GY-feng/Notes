#include <bits/stdc++.h>
using namespace std;
/*
注意到：
f[i]=f[i/2]+f[(i-1)/2]+...+f[2]+f[1]

*/
int n, t[1010];
int main()
{
    cin >> n;
    //不需要赋值了，具体请详细推函数t[1] = 1, t[2] = 2, t[3] = 2, t[4] = 4, t[5] = 4, t[6] = 6;
}
int solution(int x)
{
    int ans = 0;
    for (int i = 1; i <= n; i++) // 1~n的递推
    {
        for (int j = 1; j <= i / 2; j++)
        {
            t[i] += t[j];
        }
        t[i]++;//加本身
    }
}