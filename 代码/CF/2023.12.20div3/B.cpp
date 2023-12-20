#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

int dp[200005][1005]; //[最大经验值][需要完成的任务的个数]
const int MAX_N = 1000000000;
int main()
{
	// cin >> n;//有[1~n]个任务，最多做k个任务
	dp = {0};
}
// 第一次完成任务获得a点经验，而后每次获得b点经验
// 做更大的任务之前，必须要将更小的任务完成过
int solve()
{
	int n = 0, k = 0;
	cin >> n >> k; // n种任务,k是最多做k项任务
	vector<int> a, b;
	int aaa = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> aaa;
		a.push_back(aaa);
		use.push_back(false); // 表示还没有用过
	}
	for (int i = 0; i < n; i++)
	{
		cin >> aaa;
		b.push_back(aaa);
	}
	int tasksize = a.size()''
				   //开始dp:
				   dp[0][0] = 1;
	for (int i = 0; i < tasksize; i++)
	{
	}
}