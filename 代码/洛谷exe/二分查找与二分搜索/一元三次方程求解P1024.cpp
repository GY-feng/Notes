#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
#define  eps 1e-4//
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    cin>>a>>b>>c>>d;
    //fabs:这个函数接受一个 double 类型的参数 x，并返回其绝对值
    for (double i = -100; i <=100; i++)
    {
        double L=i,R=i+1,mid;
        if(fabs(f(L))<eps)//L可以是根
        {
            std::cout << std::fixed << std::setprecision(2) << L ;//<< std::endl;
            cout<<" ";
        }
        else if(fabs(f(R))<eps)//L可以是根
        {
            //printf("%.21f",R);
            continue;//跳过//等下一个循环当中L变到R了在输出，避免重复输出
        }
        else if(f(L)*f(R)<0)//在（L,R）上有根，则执行二分
        {
            while(R-L>eps)//在二分端点相差不超过10负四次方停止二分保持精度
            {
                mid=(R+L)/2;
                if(f(mid)*f(R)>0) R=mid;
                //mid和R的正负形是相同的，说明零点在mid的左侧
                else L=mid;//否则就是在另一侧
            }
            std::cout << std::fixed << std::setprecision(2) << L;// << std::endl;
            cout<<" ";
        }
    }
    cin>>a;
}