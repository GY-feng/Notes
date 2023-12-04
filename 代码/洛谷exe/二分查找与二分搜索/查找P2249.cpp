#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
int solve(int x)
{
        int l=1,r=n+1;
        while (l<r)//最后r和l会相等
        /*
        修改后的代码，尤其注意+1，-1的问题
        注意这里的指针l和r，对应一个左开右闭区间[l,r)
        如果有多个待查找的数据并且要找到最大的数字编号
        改成：
            if(a[mid]<=x)l=mid+1;
            else r=mid;
        */
        {
            int mid=(l+(r-1))/2;
            //有时候l+r可能会超过int 类型的极限,r-1可以避免运算溢出
            if(a[mid]>=x)
            {
                r= mid;
            }
            //else if(a[mid]>x)r=mid-1;//取区间的前一半
            else l=mid+1;//取区间的后一半
        }
        if(a[l]==x)
            return l;
        else
            return -1;
}
int main()
{
    cin>>n>>m;
    //vector<int> a(n+1);//b(m+1);
    for (int i = 1; i <=n; i++)
    {
        cin>>a[i];
    }
    for (int i =1; i <= m; i++)
    {
        int x=0;
        cin>>x;
        cout<<solve(x)<<" ";
    }
cin>>n;  
}