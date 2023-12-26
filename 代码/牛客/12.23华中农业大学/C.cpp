#include <iostream>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        total += a;
    }
    if (total - m >= 50)
    {
        cout << "KFC";
    }
    else
    {
        cout << "QAQ";
    }
}
