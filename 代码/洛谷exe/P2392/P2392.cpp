#include<bits/stdc++.h>
using namespace std;
int s1,s2,s3,s4;
int left,right,minn,ans;
int A[24],B[24],C[24],D[24];
int times(int A[]);
int main()
{
    cin>>s1>>s2>>s3>>s4;
    for (int i = 0; i < s1; i++)
    {
        cin>>A[i];
    }    
    for (int i = 0; i < s2; i++)
    {
        cin>>B[i];
    }    
    for (int i = 0; i < s3; i++)
    {
        cin>>C[i];
    }    
    for (int i = 0; i < s4; i++)
    {
        cin>>D[i];
    }

    int ggg;
    cin>>ggg;
    //分析：DFS
    /*
    思路：迭代每一个数组，按照由大到小排序，去两个大的即可
    */
}
void search(int x,int y)
{
    if()
}