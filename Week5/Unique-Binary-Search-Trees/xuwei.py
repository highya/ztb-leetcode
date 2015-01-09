class Solution:
    # @return an integer
    def numTrees(self, n):
        if n < 2:
            return n
        dct = {}
        dct[0],dct[1] = 1,1
        for i in range(2,n+1):
            dct[i] = 0
            for l in range(0,i):
                dct[i] += dct[l]*dct[i-l-1]
        return dct[n]
