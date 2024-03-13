# vector
## vector实现无序的元素的查找
//下面两个算法超时，但是lambad表达式的方法很好
```cpp
从vec第一个向元素的方向去
for (int i = 0; i < n-1; i++)
 {
  cin >> a;
  f.push_back(a);
  auto it = find_if(f.begin(), f.end(), [a](int x) {return x < a; });
  if (it == f.end())
  {
   cout << "-1" << " ";
  }
  else
  {
   cout <<*it << " ";
  }
 }
从元素的左边第一个向第一个的方向去
 int a = 0;
 cin >> n;
 cin >> a;
 f.push_back(a);
 cout << "-1" << " ";
 for (int i = 0; i < n-1; i++)
 {
  cin >> a;
  f.push_back(a);
  auto it = find_if(f.rbegin(), f.rend(), [a](int x) {return x < a; });
  if (it != f.rend())
  {
   int index = f.rend() - it - 1;
   cout << *it<<" ";
  }
  else
  {
   cout << "-1" << " ";
  }
 }
```