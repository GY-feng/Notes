//P1478
#include<bits/stdc++.h>
using namespace std;
int n,a,s,b;
struct Apples
{
    int height;
    int strength;
}apples[5005];
int cmp(Apples a,Apples b)
{
    return a.strength<b.strength;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cout.tie(0);
   // cin.tie(0);
    cin>>n>>s>>a>>b;
    for(int i=0;i<n;i++)
    {
        cin>>apples[i].height>>apples[i].strength;
    }
    sort(apples,apples+n,cmp);//按所需力气由小到大排了
    int max_height=a+b;//能够到的高度
    int number=0;
    for(int i=0;i<n;i++)
    {
        if(s>=apples[i].strength)
        {
            if(apples[i].height<=max_height)
            {
                number++;
                s-=apples[i].strength;
            }
        }
        else{
            break;
        }
    }
    cout<<number;
    cin>>number;
}