#include <iostream>
using namespace std;
string s = "";
int total;
int main()
{
    cin >> s;
    if (s.size() < 3)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 'h')
        {
            if (s[i + 1] == 'z')
            {
                if (s[i + 2] == 'y')
                    total++;
            }
        }
        if (s[i] == 'z')
        {
            if (s[i + 1] == 'z')
            {
                if (s[i + 2] == 'y')
                    total++;
            }
        }
        if (s[i] == 's')
        {
            if (s[i + 1] == 'y')
            {
                if (s[i + 2] == 'h')
                    total++;
            }
        }
    }
    cout << total * 3;
}
