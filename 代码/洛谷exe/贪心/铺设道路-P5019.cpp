#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> placeee;
int workday=0;

void pulu(vector<int> place);//从第0个元素开始,end为最末一个元素的下标

int main()
{
    cin>>n;
    int a=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        placeee.push_back(a);
    }
   pulu(placeee);
   cout<<workday;
   cin>>n;
}
void pulu(vector<int> place)//从第0个元素开始,end为最末一个元素的下标
{
    if(!place.empty())
    {
    auto minn=*(min_element(place.begin(),place.end()));//获取最小值
    auto poxiv=(min_element(place.begin(),place.end()));//获得最小值的迭代器
    auto xiabiao=poxiv-place.begin();
    if(poxiv!=place.end())
    {
        workday+=minn;//工作日期要加了
        for(int i=0;i<place.size();i++)
        {
            place[i]-=minn;
        }
    }
    vector<int> first,second;
    if(place.size()>1)//大于1，分治
    {      
        for(int i=0;i<xiabiao;i++)
        {
            first.push_back(place[i]);
        }
        for(int i=xiabiao+1;i<place.size()+1;i++)
        {
            second.push_back(place[i]);
        }
    pulu(first);
    pulu(second); 
    }
    }
    else{
        return ;
    }
}