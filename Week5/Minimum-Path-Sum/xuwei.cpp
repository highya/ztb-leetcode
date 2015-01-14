class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if(m == 0) 
            return 0;
        int n = grid[0].size();
        int **opt = new int*[m];
        for(int i=0;i<m;i++)
        {
            opt[i] = new int[n];
        }
        opt[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
        {
            opt[i][0] = opt[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++)
        {
            opt[0][j] = opt[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                opt[i][j] = min(opt[i][j-1],opt[i-1][j])+grid[i][j];
            }
        }
        int ret = opt[m-1][n-1];
        for(int i=0;i<m;i++)
        {
            delete [] opt[i];
        }
        delete[] opt;
        return ret;
    }
};
