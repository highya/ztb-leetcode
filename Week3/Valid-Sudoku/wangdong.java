public class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0; i<9; i++) {
            List listRow = new ArrayList();
            List listCol = new ArrayList();
            for(int j=0; j<9; j++){
                if(board[i][j] != '.') {
                    if(listRow.contains(board[i][j]))  return false;
                    else listRow.add(board[i][j]);
                }
                
                if(board[j][i] != '.') {
                   if(listCol.contains(board[j][i])) return false;
                   else listCol.add(board[j][i]);
                }
            }
        }
        
        for (int cell = 0; cell < 9; cell++) {
            int start_row = (cell / 3) * 3, start_col = (cell % 3) * 3;
            List list = new ArrayList();
            for (int row = start_row; row < (start_row + 3); row++) {
                for (int col = start_col; col < (start_col + 3); col++) {
                    if(board[row][col] != '.') {
                        if(list.contains(board[row][col])) return false;
                        else list.add(board[row][col]);
                    }
                }
            }
         }
         return true;
    }
}
