class Solution:
    def minPathSum(self, grid):
        if len(grid) == 0:
            return 0
        dp = grid
        m,n = len(grid),len(grid[0])
        for i in range(1,m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for i in range(1,n):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j]
        return dp[m-1][n-1]
