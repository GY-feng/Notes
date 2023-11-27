#include<bits/stdc++.h>
using namespace std;
int N,M;//N行M列
int flag[55][55];//0代表W白，1代表B蓝，2代表R红
vector<vector<int>> group;//定义二维数组表示一行的颜色构成
int total=100000000;
int main()
{
    cin>>N>>M;
    string a;
    for (int i = 1; i <= N; i++)
    {
        cin>>a;
        int column=1;
        int w=0,b=0,r=0;
        for (auto g:a)
        {
            if(g=='W')
            {
                flag[i][column]=0;
                w++;
            }
            if(g=='R')
            {
                flag[i][column]=2;
                r++;
            }
            if(g=='B')
            {
                flag[i][column]=1;
                b++;
            }
            column++;
        }
        vector<int> colour;
        colour.push_back(w);
        colour.push_back(b);
        colour.push_back(r);
        group.push_back(colour);
    }
    // //处理第一行
    // vector<int> aaa=group[0];
    // int b=aaa[1]+aaa[2];
    // total+=b;
    // //处理最后一行
    // aaa=group[N-1];
    // b=aaa[1]+aaa[0];
    // total+=b;
    //处理中间的
    /*
        定义变量isexist，作为判断是否存在全蓝色的方块
        //暴力搜索：求全蓝，少一个蓝->红、白,少两个蓝...只剩一个蓝....
    */
   int rest=N-2;//i表示最上方的白色格子有多少条
   int time=0;
   for (int i=1;i<=rest;i++)//有i行涂成红色
   {
        for (int j = 1; j <=rest; j++)
        {//int flag[55][55];//0代表W白，1代表B蓝，2代表R红
                if(i+j>N-1)
                {
                    continue;
                }
                
        }
        
   }
}