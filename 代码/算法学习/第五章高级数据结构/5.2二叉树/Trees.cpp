#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int pre[N],in[N],post[N];
int k;
struct  node
{
    int value;
    node *left, *right;//创建两个指针指向左和右
    node(int value=0,node *left=NULL,node *right=NULL)
    :value(value),left(left),right(right){}
/*
这是成员初始化列表。在冒号后面，每个成员变量被指定其初始值。
在这种情况下，value 被初始化为传递给构造函数的 value 参数的值，
left 被初始化为传递给构造函数的 left 参数的值，
right 被初始化为传递给构造函数的 right 参数的值。
*/
};

void bulidTrees(int l,int r,int &t,node * &root)//建造树
{
    int flag=-1;
    for (int i=l;i<=r;i++)//先序的第一个数是根，找到对应的中序的位置
    {
            if(in[i]==pre[i])
            {
                flag=i;break;
            }
    }
    if(flag==-1)return ;//结束
    root=new node(in[flag]);
    t++;
    if(flag>l) bulidTrees(1,flag-1,t,root->left);
    //->是一个操作符，通常用于访问类对象的成员函数和成员变量，
    //其中类对象是通过指针进行引用的。当你有一个指向类对象的指针时，你可以使用->来访问该对象的成员,不需要解引用指针
    if(flag<r)bulidTrees(flag+1,r,t,root->right);
}
/*
建树的过程：
    必须通过先序/后序+中序的其中两种方式才能确定一棵树
    eg:先+中：
        1，先序遍历的第一个数是整棵树的根，再从中序遍历中找到先序的第一个数，
        其左边的放在根的左子树上，右边的放在根的右子树上
        2，分成左右子树后递归上述的过程
*/
void preorder(node *root)
{
    if(root!=NULL)
    {
        post[k++]=root->value;
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        post[k++]=root->value;
        inorder(root->right);
    }
}void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        post[k++]=root->value;
    }
}
void remove_tress(node *root)
{
    if(root==NULL)return;
    remove_tress(root->left);
    remove_tress(root->right);
    delete root;
}
int main()
{
    int n;
    while(~scanf("%d,&n"))
    {
        for (int i = 1; i <=n; i++)
        {
            scanf("%d",&pre[i]);       
        }
        for (int k = 1; k <= n; k++)
        {
            scanf("%d",&pre[k]);       
        }
        node *root;
        int t=1;
        bulidTrees(1,n,t,root);
        k=0;
        postorder(root);
        remove_tress(root);//释放申请 的空间，不然会有内存泄漏捏
    }
}