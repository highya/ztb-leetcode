class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        if (m == 1){
            for (int j = 0; j < n; ++j) result += grid[0][j];
            return result;
        }
        if (n == 1){
            for (int i = 0; i < m; ++i) result += grid[i][0];
            return result;
        }
        for (int i = 1; i < m; ++i) grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; ++j) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                int min = grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
                grid[i][j] += min;
            }
        }
        return grid[m - 1][n - 1];
    }
};
