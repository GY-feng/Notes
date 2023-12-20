#include<bits/stdc++.h>
using namespace std;

int n=0;
map<string,int> m;//string:单词//int:出现次数
bool cmp(pair<string,int> a,pair<string,int> b);
int main(int argc, char *argv[]) 
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string a="";
	for(int i=0;i<n;i++)
	{
		cin>>a;
        m[a]++;//已经按照字典序排序了
    }
    vector<pair<string,int>>vec(m.begin(),m.end());
    sort(vec.begin(),vec.end(),cmp);
    for (auto v:vec)
    {
        cout<<v.first<<" "<<v.second<<endl;
    }
    cin>>n;
	//sort(word,word+n,pai);
	return 0;
}
bool cmp(pair<string,int> a,pair<string,int> b)
{
    if(a.second!=b.second)
    {
        return a.second>b.second;
    }
    else
    {
        return a.first<b.first;
    }
}