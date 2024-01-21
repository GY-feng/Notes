#include<bits/stdc++.h>
using namespace std;
int high[]={0,5,6,7,4,2,8,3};//在本例当中下标为0不计数哦！！！
/*
假设给定数组为 nums，其长度为 n。
创建一个数组 dp，其中 dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度。
初始化 dp[i] 为 1，因为每个单独的元素都是一个长度为 1 的递增子序列。
对于每个 i，遍历 j 从 0 到 i - 1，检查 nums[i] 是否大于 nums[j]。如果是，则更新 dp[i] = max(dp[i], dp[j] + 1)。
最终的答案是 dp 数组中的最大值，即 max(dp[0], dp[1], ..., dp[n-1])。
*/
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1); // 初始化dp数组，初始值为1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end()); // 返回dp数组中的最大值
}
int LIS_withoutDP()
{
    int len=1;
    int n=sizeof(high);
    int d[10000];
    d[1]=high[1];
    for (int i = 2; i <= n; i++)
    {
        if(high[i]>d[len])//大于d的末尾，加在后面
        {
            len++;
            d[len]=high[i];
        }
        else
        {
            int j=lower_bound(d+1,d+len+1,high[i])-d;//得到第一个比指定数字要大的数字
            d[j]=high[i];
        }
    }
    return len;
}
int main()
{

}