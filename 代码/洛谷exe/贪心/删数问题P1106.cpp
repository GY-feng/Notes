#include<bits/stdc++.h>
using namespace std;
string n ;
int main()
{
    //思路：找高峰期
    int s,i;
    cin>>n>>s;
    while(s)
    {
        for(i=0;n[i]<=n[i+1];)//找到了1个高峰辽
        {
            i++;
        }
        n.erase(i,1);//删除函数，从第i个位置删除1个
        s--;
    }
    while(n[0]=='0'&&n.size()>1)
    {
        //处理前导0，如果长度是1就不能删啦
        n.erase(0,1);
    }
    cout<<n;
}