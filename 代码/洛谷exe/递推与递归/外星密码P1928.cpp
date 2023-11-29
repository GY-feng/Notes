#include <bits/stdc++.h>
using namespace std;

string expend2();
int m;
int main()
{
    cout << expend2();
    cin >> m;
    // cout<<rezip(mima);
}
string expend2()
{
    string mima, x;
    char c;
    int times;
    while (cin >> c) // 持续读完所有的字符
    {
        if (c == '[')
        {
            cin >> times;
            x = expend2();
            while (times--)
            {
                mima += x;
            }
        }
        else if (c == ']')
        {
            return mima;
        }
        else
        {
            mima += c;
        }
    }
    return mima;
}

string expend()
{
    string mima, x;
    char c;
    int D;
    while (cin >> c)
    {
        if (c == '[')
        {
            cin >> D;     // 次数
            x = expend(); // 继续再读
            while (D--)
            {
                mima += x;
            }
        }
        else if (c == ']')
            return mima;
        else
            mima += c;
    }
    return mima;
}
// 第一版的代码，但是实测用不了捏
string rezip(string s)
{
    string ans = "";
    char a;
    for (int i = 0; i < s.length(); i++)
    {
        a = s[i];
        if (a != '[' && a != ']')
            ans += a;
        if (a == '[')
        {
            string aa = "";
            char bbb;
            int times = 1;
            char tmp = s[i + 1];
            bool isnum = isdigit(tmp);
            if (isnum)
            {
                times = s[i + 1];
                i++;
                for (int j = s.length() - 1; j > 0; j--)
                {
                    bbb = s[j];
                    if (bbb = ']')
                    {
                        for (int k = i; k < j; k++)
                        {
                            aa += s[k];
                        }
                        string b = rezip(b);
                        for (int i = 0; i < times; i++)
                        {
                            ans += b;
                        }
                        break;
                    }
                }
            }
            else
            {
                for (int j = s.length() - 1; j > 0; j--)
                {
                    bbb = s[j];
                    if (bbb = ']')
                    {
                        for (int k = i; k < j; k++)
                        {
                            aa += s[k];
                        }
                        string b = rezip(b);
                        for (int i = 0; i < times; i++)
                        {
                            ans += b;
                        }
                        break;
                    }
                }
            }
        }
    }
    return ans;
}