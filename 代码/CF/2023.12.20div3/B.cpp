#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

int dp[200005][1005]; //[�����ֵ][��Ҫ��ɵ�����ĸ���]
const int MAX_N = 1000000000;
int main()
{
	// cin >> n;//��[1~n]�����������k������
	dp = {0};
}
// ��һ�����������a�㾭�飬����ÿ�λ��b�㾭��
// �����������֮ǰ������Ҫ����С��������ɹ�
int solve()
{
	int n = 0, k = 0;
	cin >> n >> k; // n������,k�������k������
	vector<int> a, b;
	int aaa = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> aaa;
		a.push_back(aaa);
		use.push_back(false); // ��ʾ��û���ù�
	}
	for (int i = 0; i < n; i++)
	{
		cin >> aaa;
		b.push_back(aaa);
	}
	int tasksize = a.size()''
				   //��ʼdp:
				   dp[0][0] = 1;
	for (int i = 0; i < tasksize; i++)
	{
	}
}