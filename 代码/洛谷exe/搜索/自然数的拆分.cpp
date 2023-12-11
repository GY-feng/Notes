#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int a[10001] = {1}, n;
////用于存储拆分 n 的数的序列。初始值为 1，因为 a[0] 是用于开始拆分的初始值。

void search(int, int);
void print(int);
int main()
{
    cin >> n;
    search(n, 1); // 将要拆分的数n传递给s
    return 0;
}
void printff(int t)
{
    for (int i = 1; i <= t - 1; i++) // 输出一种拆分方案		[9934]	0	int

        cout << a[i] << "+";
    // if(a[t]!=t)
    cout << a[t] << endl;
}

void search(int s, int t) // s是要拆分的数值，t是要拆分的位数
{
    int i;
    for (i = a[t - 1]; i <= s; i++)
        if (i < n) // 当前数i要大于等于前一位数，且不超过n
        {
            a[t] = i; // 保存当前拆分的数i
            s -= i;   // s减去数i，s的值将继续拆分
            if (s == 0)
                printff(t); // 当s=0时，拆分结束输出结果
            else
                search(s, t + 1); // 当s>0时，继续递归
            s += i;               // 回溯，加上拆分的数(回复s开始的值)，使得产生所有可能的拆分
        }
}