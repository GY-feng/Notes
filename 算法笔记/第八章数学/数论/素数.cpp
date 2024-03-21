#include<iostream>
using namespace std;
const int MAX = 1e7;//����ռ��С��1e7ԼΪ10MB
int prime[MAX + 1]
bool visited[MAX + 1] = 0;

int E_sieve_v2(int n)//����ɸ������[2,n]�ڵ�����
{
	int k = 0;//ͳ�������ĸ���
	for (int i = 2; i * i <= n; i++)
	{
		if (!visited[i])
		{
			for (int j = i* i; j <= n; j += i)//i�ı�������������
			{
				visited[j] = true;//���Ϊ��������ɸ��
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (!visited[i])
			prime[k++] = i;//�洢����
	}
	return k;//���������ĸ���
}
int E_sieve(int n)//����ɸ������[2,n]�ڵ�����
{
	int k = 0;//ͳ�������ĸ���
	for (int i = 2; i * i <= n; i++)
	{
		if (!visited[i])
		{
			prime[k++] = i;//i���������洢��prime����
			for (int j = 2 * i; j <= n; j += i)//i�ı�������������
			{
				visited[j] = true;//���Ϊ��������ɸ��
			}
		}
	}
	return k;//���������ĸ���
}