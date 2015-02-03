class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=m-1;i>-n;i--)
        {//斜线从右下角一直平移到左上角，从斜线右上方出发开始计算。
            /*
                  #
                 ##  /
                ### /
               ####/
              24282
              13191
            */
            int row=i;
            int col=n-1;
            for(;col>-1&&row<m;row++,col--)
            {
                if(row<=-1)continue;
                int path=INT_MAX;
                if(col+1<n)
                {
                    path=grid[row][col+1];
                }
                if(row+1<m)
                {
                    path=grid[row+1][col]<path?grid[row+1][col]:path;
                }
                if(path!=INT_MAX){
                    grid[row][col]+=path;
                }
            }
        }
        return grid[0][0];
    }
};
