class Solution:
    def maxSubArray(self, A):
        maxsum,tmp = float("-inf"),float("-inf")
        for item in A:
            tmp = tmp + item if tmp > 0 else item 
            if tmp > maxsum:
                maxsum = tmp
        return maxsum
