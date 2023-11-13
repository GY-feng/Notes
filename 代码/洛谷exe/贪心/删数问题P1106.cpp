#include<bits/stdc++.h>
using namespace std;
string N;
int num[254];
int k;
int max_ele(int array[],int size);
int main()
{
    cin>>N>>k;
    for(int a=0;a<N.length();a++)
    {
        int number=N[a]-'0';
        num[a]=number;
    }
    for(int i=0;i<k;i++)
    {   int array_size = sizeof(num) / sizeof(num[0]);
        int maxindex=max_ele(num,array_size);
        num[maxindex]=-1;
    }
    string result="";
    for (int a=0;a<N.length();a++)
    {
        if(num[a]!=-1)
        result.append(to_string(num[a]));
    }
    cout<<result;
    cin>>result;
}
int max_ele(int array[],int size)
{
    int max_value = array[0];
    int max_index = 0;

    // 遍历数组，寻找最大值及其下标
    for (int i = 1; i <size; ++i) {
        if (array[i] > max_value) {
            max_value = array[i];
            max_index = i;
        }
    }
    return max_index;
}