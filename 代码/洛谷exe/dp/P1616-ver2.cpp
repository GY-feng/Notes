//十年oj一场空，不开long long 见祖宗
#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
long long t, m;
struct medicine
{
    long long time;
    long long value;
}med[10011];

//上面的solve方法会超出空间限制，所以改用下面的方法：
long long dp2[10000001];
long long solve2()
{
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= m; i++)//枚举前X种草药
    {
        for (int j = med[i].time;j<=t; j++)
        {
            dp2[j] = max(dp2[j], dp2[j - med[i].time] + med[i].value);
        }
    }
    return dp2[t];
}
int main()
{
    cin >> t >> m;//采药的时间 t 和代表山洞里的草药的数目m。
    for (int i = 1; i <= m; i++)
    {
        cin >> med[i].time >> med[i].value;
    }
    cout << solve2() << endl;
}