/***********************************************
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
***********************************************/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row,col;
        int ROW,COL;
        ROW = triangle.size();
        COL = triangle[ROW-1].size();
        
        //初始化第一列和对角线的元素
        for(row = 1; row < ROW; row++){
            triangle[row][0] += triangle[row-1][0];
            triangle[row][row] += triangle[row-1][row-1];
        }
        //每个元素找最小路径
        for(row = 2; row < ROW; row++)
            for(col = 1; col < row; col++)
                triangle[row][col] += min(triangle[row-1][col-1],triangle[row-1][col]); 
        
        //最后一行，找最小元素
        int ret = triangle[ROW-1][0];
        for(col = 0; col < COL; col++)
            ret = min(ret,triangle[ROW-1][col]);
        return ret;
    }
};
