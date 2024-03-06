#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int  MAX_N = 0x3ffff;
const int MIN_N = -0x3ffff;
//想法2：写结构体，根据结构体定义一个cmp函数进行排序
struct Order
{
	int row, col,height;
}order[10004];


int cmp(Order a,Order b);

int r, c;
int dp[103][103];
int a[103][103];
Order getorder();

int main()
{
	cin >> r >> c;
    int ordernumber=1;
    memset(dp, -1, sizeof(dp));
    memset(a,0,sizeof(a));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
            Order o;
            o.row=i,o.col=j;
			cin >> o.height;
            a[i][j]=o.height;

            order[ordernumber]=o;
            ordernumber++;
            dp[i][j]=1;
		}
	}
    sort(order+1,order+1+r*c,cmp);

	int maxx = 1;
	for (int i = 1; i <= c * r; i++)
	{
        //Order o=order[i];
        //if(o.height)
		Order o = order[i];
		int row = o.row;
		int col = o.col;

		int shang = 0;
		int xia =0 ;
		int zuo =0 ;
		int you =0 ;

        if(o.height>a[o.row-1][o.col])//上
        {
            //上是可以采用的
            shang=dp[o.row-1][o.col];
        }
        if(o.height>a[o.row+1][o.col])//下
        {
            xia=dp[o.row+1][o.col];
        }
        if(o.height>a[o.row][o.col-1])//左
        {
            zuo=dp[o.row][o.col-1];
        }
        if(o.height>a[o.row][o.col+1])//右
        {
            you=dp[o.row][o.col+1];
        }
            int maxadd=max({ shang,xia,zuo,you });
			dp[row][col] = 1 + maxadd;
		if (dp[row][col] > maxx)
			maxx = dp[row][col];

	}
	std::cout << maxx;

}

int cmp(Order a,Order b)
{
    return a.height<b.height;//有小到大排名
}
