#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> change(int x);
string result="";
int solve(int x);

int main()
{
    cin>>n;
    solve(n);
    cout<<result;
    cin>>n;
}
//2x10^4=100111000100000//15个数字
int solve(int x)
{
     vector<int> a=change(x);//转化成2进制
    //  for(int i=0;i<a.size();i++)
    //  {
    //      cout<<a[i];
    //  }
    for (int i = a.size()-1; i>2; i--)
    {
        if(a[i]==1)
        {   result+="2(";
            solve(pow(2,i));
            result+=")";
        }
    }
    if(a[2]==1)
    {
        result+="2(2)+";
    }
    if(a[1]==1)
    {
        result+="2+";
    }
    if(a[0]==1)
    {
        result+="2(0)";
    }

}
vector<int> change(int x)
{
    vector<int> num;
    while(x>1)
    {
        if(x%2==1)
        {
            num.push_back(1);
            x=x/2;
        }
        if(x%2==0)
        {
            num.push_back(0);
            x=x/2;
        }
        if(x==1)
        {
            num.push_back(1);
        }
    }
    vector<int>result;
    //for (int i = num.size()-1; i>=0; i--)
    //{
        //result.push_back(num[i]);   
    //}
    //return result;
    return num;
}
