#include<bits/stdc++.h>
using namespace std;
int pros(int min, string questions);//A:65//Z:90

int n = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0; string b = "";
		cin >> a >> b;
		cout << pros(a, b) << endl;
	}

}
int pros(int min, string questions)//A:65//Z:90
{
	int t = 0;
	map<char, int> m;//按照字典序排序
	for (int i = 0; i < questions.length(); i++)
	{
		char a = questions[i];
		m[a]++;
	}
	int solve[95];
	for (int i = 1; i < 27; i++)
	{
		solve[i + 64] = i;//Ascll表和question对应了
	}
	for (auto v : m)
	{
		if (v.second >= solve[v.first])//在这道题花费的时间比预定的时间要多了
		{
			t++;
		}
	}
	return t;
}