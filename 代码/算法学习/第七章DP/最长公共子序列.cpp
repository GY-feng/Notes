#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string s1="abcd1234",s2="acbd1234";
int LCS()
{
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }  
    }
    return dp[s1.length()][s2.length()];
}
int main()
{
    cout<<LCS()<<endl;
}