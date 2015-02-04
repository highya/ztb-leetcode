class Solution {
public:
    int min(int a,int b)
    {
        return a < b ? a : b;
    }
    int minPathSum(vector<vector<int> > &grid) {
        int row_num = grid.size();
        if(row_num <= 0)
            return 0;
        int line_num = grid[0].size();
        for(int i = 0;i < row_num;i++)
        {
            for(int j = 0;j < line_num;j++)
            {
                if((i == 0) &&(j > 0))
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if((j == 0)&& (i > 0))
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                else if((i > 0)&&(j > 0))
                    grid[i][j]=min(grid[i - 1][j] + grid[i][j] , grid[i][j - 1] + grid[i][j]);
            }
        }
        return grid[row_num - 1][line_num - 1];
    }
};
