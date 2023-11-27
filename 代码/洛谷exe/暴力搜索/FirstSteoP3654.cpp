#include<bits/stdc++.h>
using namespace std;
int r,c,k;
char place[105][105];
//定义函数：
int row();int column();
int main()
{
    cin>>r>>c>>k;
    string b="";
    for (int i = 1; i <= r; i++)
    {
        cin>>b;
        for (int j = 1; j <= c; j++)
        {
            place[i][j]=b[j-1];
        }  
    }
  
    int aaa=row();
    aaa+=column();
    if(k==2)
    {
        aaa=aaa/2;
    }
    cout<<aaa;
    cin>>aaa;
}
int row()
{
    int total=0;
    for (int i = 1; i <=c; i++)
    {
        int m=0;
        for (int j = 1; j <=c; j++)
        {
            char a=place[i][j];
            if(a=='.')
            {
                m++;
                if(m>=k)
                {
                    total++;
                }
            }
            else
            {
                m=0;
            }
        }
        m=0;
    }
    return total;
}
int column()
{
    int total=0;
    for (int i = 1; i <=c; i++)
    {
        int m=0;
        for (int j = 1; j <=c; j++)
        {
            char a=place[j][i];
            if(a=='.')
            {
                m++;
                if(m>=k)
                {
                    total++;
                }
            }
            else
            {
                m=0;
            }
        }
        m=0;
    }
    return total;
}