# R-6.5: Implement a function that reverses a list of elements by pushing them onto a stack in one order, and writing them back to the list in reversed order.
#
# 中文：实现一个函数，通过将元素按顺序推入栈中，然后以相反的顺序写回列表，来反转元素列表。
from collections import deque
# 在这个函数当中，使用deque模拟栈！！！
def reverse(arr):
    stack=deque()
    for i in arr:
        stack.append(i)
    ans=[]
    for i in stack:
        ans.append(stack.pop())
    return ans
    pass
# C-6.25
# Original: Describe how to implement the queue ADT using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.
#
# 中文：描述如何使用两个栈作为实例变量实现队列抽象数据类型（ADT），使所有队列操作的平均时间复杂度为O(1)。
#answer:
'''
刚开始两个空的栈，分别为s1和s2
入队：将一串元素推入s1当中
出队：将s1当中的元素全部pop出来，然后装入s2当中，然后从s2当中pop出元素即可
'''
# R-8.5
# Original: Describe an algorithm, relying only on the BinaryTree operations, that counts the number of leaves in a binary tree that are the left child of their respective parent.
#
# 中文：描述一个算法，仅依赖于二叉树操作，计算在二叉树中作为其各自父节点的左子节点的叶子节点数量。
'''
定义一个递归函数，参数：要查的节点a
检查a是否为空：
如果a是空节点，直接返回 0。
检查a的左子节点：
如果a左子节点存在，并且它是叶子节点，则返回 1。
如果左子节点不存在或不是叶子节点：
递归调用该函数处理左子节点和右子节点。
将返回的结果相加，并返回总数。
'''
# R-8.8.a
# Original: What is the minimum number of external nodes for a proper binary tree with height h? Justify your answer.
#
# 中文：对于高度为h的满二叉树，外部节点的最小数量是多少？请证明你的答案。
'''
第h层的节点为2^h
等比数列求和可得：
高度为h，则节点的总数量是2^(h+1)-1
则高度为h-1的树，节点的总数量是2^h-1
所以外部节点的数量就是2^h
'''

# R-8.23
# Original: Let T be an ordered tree with more than one node. Is it possible that the preorder traversal of T visits the nodes in the same order as the postorder traversal of T? If so, give an example; otherwise, explain why this cannot occur.
#
# 中文：设T为一个有多个节点的有序树。是否可能T的先序遍历以与后序遍历相同的顺序访问节点？如果可以，请给出一个例子；否则，请解释为什么这不可能发生。
'''
不行
前序遍历：
1)访问根节点2)进入左子树3)进入右子树
后序遍历：
1)进入左子树2)进入右子树3)访问根节点
前序遍历先访问根节点
后序遍历最后访问根节点
所以不行
'''
#
# R-8.29
# Original: Describe, in pseudo-code, an algorithm for recursively computing the number of descendants of a node in a tree.
#
# 中文：描述一个伪代码算法，用于递归计算树中某个节点的后代数量。
'''
def countSon(Node):
    if node is null:
        return 0
    ans=0
    que=[]#定义队列，存储孩子
    for child in Node.Sons:
        que.append(child)#孩子进入队列
    while que is not Null:
        que.pop()
        ans+=1
    return ans
'''
# R-9.11
# Original: At which positions of a heap might the largest key be stored?
#
# 中文：在堆的哪些位置可能存储最大键值？
