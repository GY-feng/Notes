#include<map>
#include<vector>
#include<iostream>
using namespace std;
//Treap树代码
int id[5000000 + 5];
struct Node
{
	int size;//以这个节点为根的子树的节点总数量，用于名次树
	int rank;//优先级
	int key;//键值
	Node* son[2];//0是左儿子，1是右儿子
	bool operator <(const Node& a)const { return rank < a.rank; }
	int cmp(int x)const//const修饰符在成员函数声明中表示该成员函数不会修改类的数据成员。
		//它可以用于对于只读操作或不修改对象状态的操作进行标记，以增加代码的清晰性和安全性。
	{
		if (x == key)return -1;
		if (x < key)
		{
			return 0;
		}
		else
			return 1;
	}
	void update()//更新size
	{
		size = 1;
		if (son[0] != NULL)size += son[0]->size;
		if (son[1] != NULL)size += son[0]->size;
	}
};
void rotate(Node*& o, int d)//d=0:左旋；d=1:右旋
{
	Node* k = o->son[d ^ 1];//位操作优化性能
	o->son[d ^ 1] = k->son[d];
	k->son[d] = o;
	o->update();
	k->update(); o = k;
}
void insert(Node*& o, int x)//将x插入到树当中
{
	if (o == NULL)
	{
		o = new Node();
		o->son[0] = o->son[1] = NULL;
		o->rank = rand();
		o->key = x;
		o->size = 1;
	}
	else
	{
		int d = o->cmp(x);//如果cmp返回-1，访问son的-1下标，不会报错吗（下标由0开始）？
		insert(o->son[d], x);
		o->update();
		if (o < o->son[d])
			rotate(o, d ^ 1);
	}
}
int kth(Node* o, int k)//找第k大的数
{
	////如果当前节点 o 为空，或者 k 不在合法范围内（小于等于0或大于树的大小），则返回 -1。
	if (o == NULL || k <= 0 || k > o->size)
		return -1;
	//如果不满足上述条件，它首先计算右子树的大小 s（如果右子树为空则为0）
	int s = o->son[1] == NULL ? 0 : o->son[1]->size;
	//然后它与 k 比较，如果 k 等于 s + 1，则表示当前节点 o 就是第k大的数，返回 o->key。
	if (k = s + 1)return o->key;
	//如果 k 小于等于 s，则说明第k大的数在右子树中，递归地在右子树 o->son[1] 中查找第k大的数。
	else if (k <= s)return kth(o->son[1], k);
	//否则，第k大的数在左子树中，递归地在左子树 o->son[0] 中查找第 k - s - 1 大的数。
	else return kth(o->son[0], k - s - 1);
}
int find(Node* o, int k)//返回元素k的名次
{//如果当前节点 o 为空，说明没有找到元素 k，返回 -1
	if (o==NULL)
	{
		return -1;
	}
	//首先，它使用 o->cmp(k) 函数来比较元素 k 和当前节点的值，得到比较结果 d。
	// 如果 d 等于 -1，表示元素 k 等于当前节点值，返回右子树的大小加1（如果右子树为空则为1），
	// 表示当前节点是第 k 大的数。
	int d = o->cmp(k);
	if (d == -1)
		return o->son[1] == NULL ? 1 : o->son[1]->size + 1;
	//如果 d 等于 1，表示元素 k 大于当前节点值，递归地在右子树 o->son[1] 中查找元素 k。
	else if (d == 1)return find(o->son[d], k);
	//否则，d 等于 0，表示元素 k 小于当前节点值，它递归地在左子树 o->son[0] 中查找元素 k。
	else
	{
		//如果在左子树中找到了元素 k，它将返回 tmp + 1 + o->son[1]->size，其中 tmp 是元素 k 在左子树中的名次
		// o->son[1]->size 是右子树的大小，因此返回的是整个树中元素 k 的名次。
		int tmp = find(o->son[d], k);
		if (tmp == -1)
		{
			return -1;
		}
		else
			return o->son[1] == NULL ? tmp + 1 : tmp + 1 + o->son[1]->size;
	}
}


int main()
{
	int n;
	while (~scanf("%d", &n) && n)
	{
		srand(time(NULL));//time(NULL)返回当前的时间（自 1970 年 1 月 1 日以来经过的秒数）。srand函数是用来设置随机数发生器的种子，
		//它需要一个整数作为种子。种子的选择会影响随机数生成的序列。通常情况下，我们希望每次程序运行时生成的随机数序列都是不同的，而不是每次都产生相同的序列。
		//因此，srand(time(NULL)) 的作用是使用当前时间作为种子，以确保每次程序运行时都会产生不同的随机数序列。这样做可以增加随机性，
		//使得每次运行程序时得到的随机数序列都是不同的。通常这是在需要产生伪随机数的程序中使用的常见技巧。
		int k, g;
		scanf("%d%d", &k, &g);
		//创建一个新的二叉搜索树节点 root，并初始化其属性，包括左右子树为 NULL，随机排名 
		//rank，关键字 key 为 g，以及大小 size 为 1。同时，将 id[g] 赋值为 k。
		Node* root = new Node();
		root->son[0] = root->son[1] = NULL;
		root->rank = rand(); root->key = g; root->size = 1;
		id[g] = k;
		//表示当前输入的 k 和相应的排名为 1。
		printf("%d%d\n", k, 1);
		for (int i = 2; i <= n; i++)
		{
			scanf("%d%d", &k, &g);
			id[g] = k;
			//调用 insert(root, g) 将新的关键字 g 插入二叉搜索树。
			insert(root, g);
			//调用 find(root, g) 获取关键字 g 在二叉搜索树中的名次，保存在变量 t 中。
			int t = find(root, g);
			//调用 kth(root, t - 1) 和 kth(root, t + 1) 获取第 t - 1 和第 t + 1 大的数，分别保存在变量 ans1 和 ans2 中。
			int ans1, ans2, ans;
			ans1 = kth(root, t - 1);//找比t-1大的数
			ans2 = kth(root, t + 1);
			//根据一定的条件判断，更新 ans 的值，最后输出格式化的结果 printf("%d%d\n", k, id[ans])，
			// 表示当前输入的 k 和关键字 ans 对应的名次。
			//这是一个条件判断语句。它首先检查变量 ans 是否不等于 -1（即之前没有找到有效的 ans），
			// 并且 ans2 也不等于 -1。
			if (ans != -1 && ans2 != -1)
				//如果两者都满足条件，说明 ans 和 ans2 都有效，可以比较它们的差值，然后根据差值的大小来决定选择哪一个作为新的 ans。
				// 如果 ans1 - g 和 g - ans2 相等，那么选择 ans2，否则选择差值更小的那个。
				ans = ans1 - g >= g - ans2 ? ans2 : ans1;
			//如果上述条件不成立，那么检查 ans 是否等于 -1。如果等于 -1，说明之前没有有效的 ans，此时直接将 ans2 赋值给 ans。
			else if (ans == -1)ans = ans2;
			//如果前两个条件都不满足，那么说明 ans 和 ans2 都是有效的，但是它们的差值比较大。此时，直接将 ans1 赋值给 ans。
			else ans = ans1;
			printf("%d%d\n", k, id[ans]);
		}

	}

}