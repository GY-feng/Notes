#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    priority_queue<int,vector<int>,greater<int>> Q;//优先队列，最小的在队首
    while(getline(cin,s)&&s!="END")//输入字符
    {
        int t=1;
        sort(s.begin(),s.end());//字典序排序
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=s[i-1])
            {
                Q.push(t);
                t=1;
            }
            else 
                t++;
        }
        Q.push(t);
        int ans=0;
        while(Q.size()>1)
        {
            int a=Q.top();Q.pop();
            int b=Q.top();Q.pop();//提取队列当中最小的两个
            Q.push(a+b);
            ans+=a+b;//直接计算编码的长度即可
        }
        Q.pop();
    }
}