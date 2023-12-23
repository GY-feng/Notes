#include <iostream>
using namespace std;
int ascllmap[230];
void init()
{
    ascllmap[65] = 1;
    ascllmap[66] = 2;
    ascllmap[68] = 1;
    // ascllmap[71] = 1;
    ascllmap[79] = 1;
    ascllmap[80] = 1;
    ascllmap[81] = 1;
    ascllmap[82] = 1;

    ascllmap[97] = 1;
    ascllmap[98] = 1;
    ascllmap[100] = 1;
    ascllmap[101] = 1;
    ascllmap[103] = 1;
    ascllmap[111] = 1;
    ascllmap[112] = 1;
    ascllmap[113] = 1;

    ascllmap[48] = 1;
    ascllmap[52] = 1;
    ascllmap[54] = 1;
    ascllmap[56] = 2;
    ascllmap[57] = 1;
    // ascllmap[65] = 1;
}
int main()
{
    init();
    string s = "";
    cin >> s;
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        total += ascllmap[s[i]];
    }
    cout << total;
}
