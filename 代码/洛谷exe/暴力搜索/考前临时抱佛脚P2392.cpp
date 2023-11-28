#include<bits/stdc++.h>
using namespace std;
int s1,s2,s3,s4;
vector<int> ss1,ss2,ss3,ss4;
int main()
{
    cin>>s1>>s2>>s3>>s4;
    int aaaa=0;
    for (int i = 0; i < s1; i++)
    {
        cin>>aaaa;
        ss1.push_back(aaaa);
    }
    for (int i = 0; i < s2; i++)
    {
        cin>>aaaa;
        ss2.push_back(aaaa);
    }    
    for (int i = 0; i < s3; i++)
    {
        cin>>aaaa;
        ss3.push_back(aaaa);
    }    
    for (int i = 0; i < s4; i++)
    {
        cin>>aaaa;
        ss4.push_back(aaaa);
    }
    sort(ss1.begin(),ss2.end());
}