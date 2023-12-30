#include <iostream>
using namespace std;
char getchar(char a, char b);
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int row, col;
        int mat[3][3];
        string a = "";
        for (int i = 0; i < 3; i++)
        {
            cin >> a;
            for (int k = 0; k < 3; k++)
            {
                mat[i][k] = a[k];
                if (mat[i][k] == '?')
                {
                    row = i, col = k;
                }
            }
        }
        if (row == 1) // 处理?在第二列的情况
        {
            char first = mat[row - 1][col];
            char third = mat[row + 1][col];
            cout << getchar(first, third) << endl;
        }
        else if (row == 0) // 处理在第一列的情况
        {
            char first = mat[row + 2][col];
            char third = mat[row + 1][col];
            cout << getchar(first, third) << endl;
        }
        else
        {
            char first = mat[row - 1][col];
            char third = mat[row - 2][col];
            cout << getchar(first, third) << endl;
        }
    }
}
char getchar(char a, char b)
{
    if (a == 'A' && b == 'B')
        return 'C';
    if (a == 'A' && b == 'C')
        return 'B';
    if (a == 'B' && b == 'A')
        return 'C';
    if (a == 'B' && b == 'C')
        return 'A';
    if (a == 'C' && b == 'A')
        return 'B';
    if (a == 'C' && b == 'B')
        return 'A';
}
