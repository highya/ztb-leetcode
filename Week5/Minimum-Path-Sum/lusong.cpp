class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row,column;
        int ROW = grid.size();
        int COL = grid[0].size();
        if(ROW == 0 || COL == 0)
            return 0;
        
        int f[ROW][COL];
        f[0][0] = grid[0][0];
        //初始化第一行，第一列的路径长度。
        for(column = 1; column < COL; column++) 
            f[0][column] = f[0][column-1] + grid[0][column];
        for(row = 1; row < ROW; row++)
            f[row][0] = f[row-1][0] + grid[row][0];
            
        //依次求出到grid[][] 每个元素的路径长度    
        for(row = 1; row < ROW; row++) 
            for(column = 1; column < COL; column++)
                f[row][column] = grid[row][column] + min(f[row][column-1],f[row-1][column]);
        return f[ROW-1][COL-1];
    }
};
