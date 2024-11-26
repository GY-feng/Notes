# R-10.4 What is the worst-case running time for inserting n key-value pairs into an initially empty map M that is implemented with the UnsortedTableMap class?


# Answer：O(n)

# R-10.6 Which of the hash table collision-handling schemes could tolerate a load factor above 1 and which could not?

# 链表法 Separate chaining

# R-10.9 Draw the 11-entry hash table that results from using the hash function, h(i) = (3i+5) mod 11, to hash the keys 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, and 5, assuming collisions are handled by chaining.


'''
index    key
0        -13
1        -94-39
2
3
4
5        -44-88-11
6
7
8        -12-23
9        -16-5
10       -20


'''

# R-10.13 What is the worst-case time for putting n entries in an initially empty hash table, with collisions resolved by chaining? What is the best case?


'''
最坏：全部都在同一个索引，时间复杂度为o(n^2)
最好：都在不同的索引，时间复杂度为o(n)
'''

# R-11.2 Insert, into an empty binary search tree, entries with keys 30, 40, 24, 58, 48, 26, 11, 13 (in this order). Draw the tree after each insertion.

# 中文翻译：R-11.2 将键值为 30、40、24、58、48、26、11、13 的条目（按此顺序）插入到一个空的二叉搜索树中。每次插入后绘制树的结构。

# R-12.7 Suppose we are given two n-element sorted sequences A and B each with distinct elements, but potentially some elements that are in both sequences. Describe an O(n)-time method for computing a sequence representing the union A ∪ B (with no duplicates) as a sorted sequence.

# 中文翻译：R-12.7 假设给定了两个包含 n 个元素的排序序列 A 和 B，每个序列的元素都是不同的，但可能有一些元素出现在两个序列中。描述一种 O(n) 时间方法来计算表示 A ∪ B（无重复元素）作为排序序列的结果。

# R-12.8 Suppose we modify the deterministic version of the quick-sort algorithm so that, instead of selecting the last element in an n-element sequence as the pivot, we choose the element at index ⌊n/2⌋. What is the running time of this version of quick-sort on a sequence that is already sorted?

# 中文翻译：R-12.8 假设我们修改了快速排序算法的确定性版本，不再选择一个 n 元素序列中的最后一个元素作为基准，而是选择索引为 ⌊n/2⌋ 的元素。对于一个已经排序的序列，这个版本的快速排序的运行时间是多少？