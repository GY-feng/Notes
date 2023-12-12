#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100
/*
学习：占位和退位的思想，对角线的表示形式
*/
int a[MAX_N], n, ans = 0;
int b1[MAX_N], b2[MAX_N], b3[MAX_N]; // 分别记录y,x+y,x-y+15是否被占用
/*
b2数组（对角线）：
(左下与右上的线）
b2[x + i] 表示第 x 行和第 i 列的对角线是否被占用。
对于每一个皇后，它的位置是 (x, i)，那么它所在的对角线编号为 x + i。
如果 b2[x + i] 的值为 1，说明在这个对角线上已经有皇后存在。
b3数组（反对角线）：

b3:(左上与右下的线）
b3[x - i + 15] 表示第 x 行和第 i 列的反对角线是否被占用。
对于每一个皇后，它的位置是 (x, i)，那么它所在的反对角线编号为 x - i + 15。
加上常数 15 是为了保证数组的索引不会出现负数。
如果 b3[x - i + 15] 的值为 1，说明在这个反对角线上已经有皇后存在。
*/
void dfs(int x)
{
    if (x > n)
    {
        ans++;
        if (ans <= 3)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) // 模拟列的情况
    {
        // b1记录第i排竖排是否被占用
        // b2
        if (b1[i] == 0 && b2[x + i] == 0 && b3[x - i + 15] == 0)
        {
            a[x] = i; // 记录展位的地方
            b1[i] = 1;
            b2[x + i] = 1;
            b3[x - i + 15] = 1; // 占位
            dfs(x + 1);
            b1[i] = 0;
            b2[x + i] = 0;
            b3[x - i + 15] = 0; // 取消占位
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << ans;
}