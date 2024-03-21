#include<iostream>
using namespace std;
const int MAX = 1e7;//定义空间大小，1e7约为10MB
int prime[MAX + 1]
bool visited[MAX + 1] = 0;

int E_sieve_v2(int n)//埃氏筛，计算[2,n]内的素数
{
	int k = 0;//统计素数的个数
	for (int i = 2; i * i <= n; i++)
	{
		if (!visited[i])
		{
			for (int j = i* i; j <= n; j += i)//i的倍数都不是素数
			{
				visited[j] = true;//标记为非素数，筛掉
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (!visited[i])
			prime[k++] = i;//存储素数
	}
	return k;//返回素数的个数
}
int E_sieve(int n)//埃氏筛，计算[2,n]内的素数
{
	int k = 0;//统计素数的个数
	for (int i = 2; i * i <= n; i++)
	{
		if (!visited[i])
		{
			prime[k++] = i;//i是素数，存储到prime当中
			for (int j = 2 * i; j <= n; j += i)//i的倍数都不是素数
			{
				visited[j] = true;//标记为非素数，筛掉
			}
		}
	}
	return k;//返回素数的个数
}