class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self,triangle):
        if len(triangle) == 0:
            return 0
        opt = {}
        opt[0] = triangle[0][0]
        if len(triangle) == 1:
            return opt[0]
        for i in range(0,len(triangle)):
            opt[i] = triangle[len(triangle)-1][i]
        for i in range(len(triangle)-2,-1,-1):
            for j in range(0,i+1):
                opt[j] = triangle[i][j] + min(opt[j],opt[j+1])
        return opt[0]
