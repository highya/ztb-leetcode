public class Solution {
    public int minPathSum(int[][] grid) {
        int[][] sum = grid;
        int rows = grid.length;
        int columns = grid[0].length;
        //the first row
        for(int m = 1;m<columns;m++){
            sum[0][m]=sum[0][m]+sum[0][m-1];
        }
        //the first column
        for(int n = 1;n<rows;n++){
            sum[n][0]=sum[n][0]+sum[n-1][0];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<columns;j++){
                sum[i][j]=(sum[i-1][j]<sum[i][j-1]?sum[i-1][j]:sum[i][j-1])+grid[i][j];
            }
        }
        return sum[rows-1][columns-1];
    }
}
