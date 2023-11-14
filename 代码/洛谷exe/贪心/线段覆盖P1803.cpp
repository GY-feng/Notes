#include<bits/stdc++.h>
using namespace std;
int n;
struct Race
{
    int begin;
    int end;
}race[1000005];
int num=0;
int cmp(Race a,Race b)
{
    return a.end<b.end;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>race[i].begin>>race[i].end;
    }
    sort(race,race+n,cmp);
    num++;
    int endtime=race[0].end;
    for(int i=1;i<n;i++)
    {
        if(race[i].begin<endtime)
        {
            race[i].end=-1;//不可以哟
        }
        else
        {
            endtime=race[i].end;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(race[i].end!=-1)
            num++;
    }
    cout<<num;
    cin>>n;
}