/*
解题思路：
设组合为abcd
a,b都为0组合12,21不可连，那么答案是max(2c,2d)
a,ba,b数量相等，那么All可以上队答案a+b+2c+2d
排成队的队伍之间男女的数量最多相差1，所以其他情况下：答案：2*min(a,b)+1+2c+2d
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    if(a==0&&b==0)
    {
        cout<<max(2*c,2*d);
    }
    else if(a==b)
    {
        cout<<a+b+2*(c+d);
    }
    else{
        cout<<2*min(a,b)+1+2*c+2*d;
    }
}