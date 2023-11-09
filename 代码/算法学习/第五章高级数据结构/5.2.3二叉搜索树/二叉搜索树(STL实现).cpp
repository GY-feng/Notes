#include<map>
#include<vector>
#include<iostream>
using namespace std;
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;//和尚的人数
    mp.clear();
    mp[1000000000] = 1;
    while (n--)
    {
        int id, g;
        cin >> id >> g;//新和尚id,等级是g
        mp[g] = id;//新和尚进队
        //map[键]=值,map[等级]=id；
        int ans;
        auto it = mp.find(g);//找到排好序的位置
        if (it == mp.begin())
        {
            ans = (++it)->second;//如果 it 确实指向 mp 的起始位置，移动迭代器 it，
            //然后获取其后续元素的 second（即该元素的值），并将其赋给 ans
            //访问元素的值，即访问id
        }
        else
        {
            auto it2 = it;
            it2--; it++;//前后等级接近的两个老和尚
            if (g - it2->first <= it->first - g)//访问元素的键（等级）
                ans = it2->second;
            else ans = it->second;//将答案搞成那个等级距离较近的和尚
        }
        cout << id << " " << ans << endl;

    }

}