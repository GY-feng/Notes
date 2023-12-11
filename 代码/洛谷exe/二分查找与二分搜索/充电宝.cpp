#include <iostream>
#include <algorithm>
using namespace std;
int n, p;
const double MAX_N = 1e9 + 4;
struct Equipment
{
    double a;
    double b;
} equipment[100005];
double Find(double lbound, double rbound); // 使用前确保答案在[L,R]内//注意，开始的L=0，数组从第1位开始放数字捏

int main()
{
    cin >> n >> p; // p:每秒充的能量
    double sum = 0;
    // ai:每秒消耗的能量，bi:开始时存储的能量
    for (int i = 1; i <= n; i++)
    {
        cin >> equipment[i].a >> equipment[i].b;
        sum += equipment[i].a;
    }
    if (sum <= p) // 设备消耗品
    {
        cout << "-1";
        return 0;
    }
    double ans = Find(0, MAX_N);
    cout << ans;
    return 0;
}
bool P(double x)
{
    double energy = p * x; // 可以提供的能量
    double sum = 0;        // 坚持那么多秒需要的能量
    for (int i = 1; i <= n; i++)
    {
        if (equipment[i].a * x <= equipment[i].b) // 原有的能量能撑过那么久了
        {
            continue; // 忽略它
        }
        else
        {
            sum += (equipment[i].a * x - equipment[i].b); // 这里充能;
        }
    }
    return sum <= energy;
}
double Find(double lbound, double rbound) // 使用前确保答案在[L,R]内//注意，开始的L=0，数组从第1位开始放数字捏
{
    double ans, mid;
    while (rbound - lbound > 1e-6)
    {
        mid = (lbound + rbound) / 2;
        if (P(mid))
        {
            lbound = mid;
        }
        else
        {
            rbound = mid;
        }
    }
    return lbound;
}