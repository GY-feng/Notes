#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e5 + 10;
ll n, m, s[mn];
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (ll l, r, i = 1; i <= m; ++i)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << '\n';
    }
    return 0;
}