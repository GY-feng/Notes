#include<bits/stdc++.h>
using namespace std;
int m;
int fields[305][305]={0};
struct Stars
{
    int x;int y;int time;
}star[50005];

int main()
{
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>star[i].x>>star[i].y>>star[i].time;
    }
    
}