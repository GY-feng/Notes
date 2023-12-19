#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int c;
    cin >> c;
    cout << (c + m - 1) / m << ' ';   // 向上取整
    cout << (c % m == 0 ? m : c % m); // 每行最后一个为列数的倍数
    return 0;
}