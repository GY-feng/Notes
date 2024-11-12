# R-8.23 Let T be an ordered tree with more than one node.
# Is it possible that the preorder traversal of T visits the nodes in the same order as the postorder traversal of T?
# If so, give an example; otherwise, explain why this cannot occur.

'''
Answer：不可能
前序遍历访问顺序：根节点，左节点，右节点
后序遍历访问顺序：左节点，右节点，根节点
'''
# R-8.29 Describe, in pseudo-code, an algorithm for recursively computing the number of descendants of a node in a tree.
# R-8.29 描述一个伪代码算法，用于递归计算树中节点的后代数量。
'''
childrennum=0
def count(Node):
    if Node is null:
        return 0
    for child in Node.childrens:
        childrennum=1+childrennum+count(child)
    return childrennum

'''



# R-9.10 At which positions of a heap might the third smallest key be stored?
# R-9.10 在堆中，第三小的关键字可能存储在哪些位置？
'''
按照最小堆的情况：
1，根节点的子节点 。2，根节点的子节点的子节点
'''


# R-9.12 Consider a situation in which a user has numeric keys and wishes to have a priority queue that is maximum-oriented.
# How could a standard (min-oriented) priority queue be used for such a purpose?

'''
加入元素的时候，去相反数放入最小值优先的队列，取出的时候，再去相反数即可
'''

# R-9.7 Illustrate the execution of the selection-sort algorithm on the following input sequence: (22,15,36,44,10,3,9,13,29,25).
# R-9.7 演示选择排序算法在以下输入序列上的执行：(22,15,36,44,10,3,9,13,29,25)。
'''
(3, 15, 36, 44, 10, 22, 9, 13, 29, 25)
(3, 9, 36, 44, 10, 22, 15, 13, 29, 25)
(3, 9, 10, 44, 36, 22, 15, 13, 29, 25)
(3, 9, 10, 13, 36, 22, 15, 44, 29, 25)
(3, 9, 10, 13, 15, 22, 36, 44, 29, 25)
(3, 9, 10, 13, 15, 22, 36, 44, 29, 25)
(3, 9, 10, 13, 15, 22, 25, 44, 29, 36)
(3, 9, 10, 13, 15, 22, 25, 29, 44, 36)
(3, 9, 10, 13, 15, 22, 25, 29, 36, 44)

'''
# R-9.13 Illustrate the execution of the in-place heap-sort algorithm on the following input sequence: (2,5,16,4,10,23,39,18,26,15).
# R-9.13 演示就地堆排序算法在以下输入序列上的执行：(2,5,16,4,10,23,39,18,26,15)。

'''
最小堆排序后：
            2
         5     6
        4  10 23 39
      18  26  
     15
取出2，然后将15放到原先2的位置上，执行下沉操作，最终4会被放到根节点上……
如此循环直到全部取出
'''

# R-9.17 Let H be a heap storing 15 entries using the array-based representation of a complete binary tree.
# R-9.17 设 H 为一棵使用数组表示法存储 15 个条目的堆（完全二叉树）。

# What is the sequence of indices of the array that are visited in a preorder traversal of H?
# 在 H 的先序遍历中，访问的数组索引序列是什么？
'''
根节点，左节点，右节点
i,2*i+1,2*i+2

'''
# What about an inorder traversal of H?
# H 的中序遍历呢？
'''
左节点，根节点，右节点
2*i+1,i,2*i+2

'''
# What about a postorder traversal of H?
# H 的后序遍历呢？
'''
左节点，右节点,根节点
2*i+1,2*i+2,i

'''

