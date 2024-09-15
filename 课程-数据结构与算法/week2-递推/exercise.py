# R-4.1 Describe a recursive algorithm for finding the maximum element in a sequence, 
# S, of n elements. What is your running time and space usage?

# Answer:描述：比较序列的第一个元素和传下来的maxnum元素，当剩下来的序列不为1的时候，进行递归，将序列的第一个元素去掉，切片进行迭代。running time:O(n)，space useage:O(n)


# R-4.7 Describe a recursive function for converting a string of digits into the integer it 
# represents. For example, 13531 represents the integer 13,531.

# Answer:描述：得到的序列不为空的时候，将第一个元素通过Ascll码转化为int，然后将这个元素从序列当中去除，剩下的序列不为空的时候，进入递归，循环以上操作，直到剩下的序列为空，停止。
# C-4.9 Write a short recursive Python function that finds the minimum and maximum
# values in a sequence without using any loops.
def Find_nums(seq):
    if len(seq)==1:#只有一个元素那就是最大又是最小的咯
        return (seq[0],seq[0])
    else:
        return (Find_max(seq[1:],seq[0]),Find_min(seq[1:],seq[0]))
    pass
def Find_max(seq,maxnum):#两个参数，一个序列本身，一个maxnum
    if seq[0]>maxnum:
        maxnum=seq[0]
    if len(seq)==1:#seq只剩下当前这一个元素了
        return maxnum
    return Find_max(seq[1:],maxnum)
    pass


def Find_min(seq, minnum):  # 两个参数，一个序列本身，一个minnum
    if seq[0]<minnum:
        minnum=seq[0]
    if len(seq)==1:#seq只剩下当前这一个元素了
        return minnum
    return Find_min(seq[1:],minnum)
    pass


s=[23,24,21,18,1,7,1000]
print(Find_nums(s))

# C-4.16 Write a short recursive Python function that takes a character string s and
# outputs its reverse. For example, the reverse of pots&pans would be snap&stop.
def reverse_string(str,l,r):#左边界和右边界
    if l<r:
        str[l],str[r]=str[r],str[l]
        return reverse_string(str,l+1,r-1)
    print(str)#打印str
    pass
s="abcdefg"
str=list(s)
reverse_string(str,0,len(str)-1)

# C-4.17 Write a short recursive Python function that determines if a string s is a
# palindrome, that is, it is equal to its reverse. For example, racecar and
# gohangasalamiimalasagnahog are palindromes

def palindromes_string(str,l,r):#左边界和右边界
    if l<r:
        if str[l]==str[r] and str[r]==str[l]:
            return palindromes_string(str,l+1,r-1)
        else:
            return False
    else:
        return True
    pass
s="gohangasalamiimalasagnahog"
str=list(s)
print(palindromes_string(str,0,len(str)-1))


