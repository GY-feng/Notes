# C++学习：
## 主函数：
    除了int main()以外也可以写成signed main()或者int32 main()是一样的意思，一方如果需要把全文的int替换成long long
## 输入输出流：
cin>>变量名，这个表达式本身会返回一个布尔值，表示当前是否读到了EOF，为false则表示遇到了EOF
```c++
#include <bits/stdc++.h>
using namespace std;
int v, sum;
signed main()
{
while (cin >> v)
{ //类比EOF!=scanf("%d",&v)
sum += v;
}
cout << sum;
return 0;
}
```
读写加速：
使用了读写加速后，不能同时使用 cin,scanf 与 cout,printf ，否则可能出错
```c++
ios::sync_with_stdio(false);//false即0,是C++的布尔值bool类型
cin.tie(0); //0即空指针，可以写成C++的nullptr或C语言的NULL
cout.tie(0);
```
## 传引用：
使用 变量类型& 传引用变量名 定义一个传引用变量(称为左值传引用)。
赋值一个传引用变量，直接把变量赋给它即可，即 传引用变量名 = 被引用变量名 。声明时必须赋值，且不能改变初始化再指向其他对象。
传引用可以视作一个变量的别名。即调用传引用等效于调用被引用变量本身。如：
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
int x = 114515;
int &y = x;
--y;
printf("%d %d", y, x);//都是114514
return 0;
}
```
```c++
#include <bits/stdc++.h>
using namespace std;
void myswap(int &x, int &y)
{
int t = x;
x = y;
y = t;
}
int main()
{
int a = 233, b = 666;
myswap(a, b);
cout << a << ' ' << b; // 666 233
return 0;
}
```
传引用的功能是代替指针。特别注意不能传引用一个数组。
使用传引用的目的：
修改值
对很大的数据对象(结构体)，提高运行速度，避免拷贝
对于认为不需要修改值的用途里，可以写成 const 类型& 变量 。这在重载比较函数里很常用。

## 重载运算符：
多维数组适合开普通的数组
```c++
返回值 operator 运算符(左参数, 右参数)
{
函数体
}
```
## sort函数：
需要逆序即使用 greater<类型>() 即可获得该函数变量。
升序同理 less<类型>() 。如上述代码改为：
```c++
sort(a, a + 3, greater<int>());
```
## for-each 函数：
```c++
//for-each:
    int x[5]={2,3,4,5,6};
    for(int v:x)//可以用这个来简单的输出一个vector的元素
    {
        cout<<v<<endl;
    }
    vector<int> a={2,3,4,5,6};
    for(int x:a)
    {
        cout<<x<<endl;
    }
```
## 匿名函数
```c++
    auto f=[](int a ,int b){return a+b;};//匿名函数
```
## 保留小数：
要输出特定位小数，如保留小数点后九位，则使用 
```c++
cout<<fixed<<setprecision(9)<<x；
```
# 深度搜索基本模板：
```c++
int search(int t)
{
    if(满足输出条件)
    {
        输出解;
    }
    else
    {
        for(int i=1;i<=尝试方法数;i++)
            if(满足进一步搜索条件)
            {
                为进一步搜索所需要的状态打上标记;
                search(t+1);
                恢复到打标记前的状态;//也就是说的{回溯一步}
            }
    }
}
```
