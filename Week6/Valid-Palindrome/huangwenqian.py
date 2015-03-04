class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        s=s.lower()             #测试用例里没考虑s为None的情况，感觉还是应该加上
        a=list(s)
        b=[]
        for i in range(len(a)):
            if a[i].isdigit() or a[i].isalpha():
                b.append(a[i])
        c=b[::-1]
        return c==b
