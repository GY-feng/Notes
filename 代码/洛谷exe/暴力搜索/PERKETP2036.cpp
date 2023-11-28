#include<bits/stdc++.h>
using namespace std;
int n=0;
struct Ingredients
{
    int suandu;int kudu;
}ingredients[15];
int total;
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>ingredients[i].suandu>>ingredients[i].kudu;
    }
    //酸度：乘积，苦度：总和
    total=99999999;
    //初始值
    //思路考虑：子集的方法：
    for (int i = 1; i < (1<<n); i++)
    {
        int position=1;
        int t_suandu=1;
        int t_kudu=0;
        for (int j = 0; j <=n; j++)
        {
                if(i&(1<<j))//判断哪几位数为1
                {
                    t_suandu*=ingredients[j].suandu;
                    t_kudu+=ingredients[j].kudu;
                }
        }
        total=min(total,abs(t_suandu-t_kudu));
    }

    cout<<total;
    cin>>n;
}