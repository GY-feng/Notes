#include <bits/stdc++.h>
using namespace std;
int n, a[200020], b[200020], i, ans = -2147483647;

// b[i] 表示截止到 i 时，第 i 个数所在的有效序列的元素和。

int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1)
            b[i] = a[i];
        else
            b[i] = max(a[i], b[i - 1] + a[i]);
        ans = max(ans, b[i]);
    }
    cout << ans;
    return 0;
}