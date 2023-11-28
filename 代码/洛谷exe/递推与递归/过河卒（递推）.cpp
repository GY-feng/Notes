#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[32][32] = {0};
int ctrl[32][32], n, m, hx, hy;
int d[9][2] = {{0, 0}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int main()
{
    cin >> n >> m >> hx >> hy;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 9; i++)
    {
        int tmpx = hx + d[i][0], tmpy = hy + d[i][1];
        if (tmpx >= 0 && tmpx <= n && tmpy >= 0 && tmpy <= m)
        {
            ctrl[tmpx][tmpy] = 1;
        }
    }
    f[0][0] = 1 - ctrl[0][0]; // 原点是控制点那就无路可走了咯
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (ctrl[i][j]) // 如果这个点是控制点
                continue;
            if(i!=0)
                f[i][j]+=f[i-1][j];
            if(j!=0)
                f[i][j]+=f[i][j-1];
        }
    }
    cout<<f[n][m];
    // 获取程序结束时间点
    auto end_time = std::chrono::high_resolution_clock::now();
    // 计算时间差
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // 输出程序运行时间
    std::cout << "程序运行时间: " << duration.count() << " 微秒" << std::endl;
    cin>>hx;
}