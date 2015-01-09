class Solution:
    def maxSubArray(self, A):
        maxsum,tmp = float("-inf"),float("-inf")
        for item in A:
            tmp = item if tmp < 0 else tmp+item 
            if tmp > maxsum:
                maxsum = tmp
        return maxsum
