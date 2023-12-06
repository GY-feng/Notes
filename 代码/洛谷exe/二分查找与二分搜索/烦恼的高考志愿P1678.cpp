#include<bits/stdc++.h>
using namespace std;
int m,n,school[100005],grades[1000005];
long long ans=0;
int  main()
{
    cin>>m>>n;//m个学校，n个学生
    for (int i = 1; i <= m; i++)
    {
        cin>>school[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>grades[i];
    }
    sort(school+1,school+m+1);
    //sort(grades,grades+n);
    for (int i = 1; i <= n; i++)
    {
        int L=0,R=m+1,mid;
        //mid=L+R>>1;
        //ans=abs(grades[i]-school[0]);//第一个不满意度
        while(L<R)
        {
            mid=(L+R)/2;  
            if(school[mid]<=grades[i])
            {
                //ans=abs(grades[i]-school[mid]);
                ////pixot=mid;
                L=mid+1;
            }
            else{
                R=mid;
                //L++;
            }
        }
        if(grades[i]<=school[1])
            ans+=school[1]-grades[i];
        else 
            ans+=min(abs(school[L-1]-grades[i]),abs(school[L]-grades[i]));
        //degree+=abs(ans);    
    }
    cout<<ans;
}
// int Find(int L,int R)//使用前确保答案在[L,R]内
// {
//     int ans,mid;
//     while(L<=R)//闭区间上的二分条件
//     {
//         int mid=L+R>>1;
//         if(P(mid))//条件成立
//             ans=mid;R=mid-1;
//             //只需要记录满足条件的mid，最后循环一定会结束，也一定会在ans当中保留正确的答案
//         else 
//             L=mid+1;//L和R不用考虑+1和-1，全部写上去
//     }
//     return ans;
// }