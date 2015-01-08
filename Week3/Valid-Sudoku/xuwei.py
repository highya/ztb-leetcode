class Solution:
    def isValidSudoku(self, board):
        for i in range(9):
            line,row = [],[]
            for j in range(9):
                if board[i][j] != '.':
                    line.append(board[i][j])
                if board[j][i] != '.':
                    row.append(board[j][i])
            if len(line) != len(set(line)) or len(row) != len(set(row)):
                return False
        for i in range(3):
            for j in range(3):
                sqr = []
                for m in range(i*3,i*3+3):
                    for n in range(j*3,j*3+3):
                        if board[m][n] != '.':
                            sqr.append(board[m][n])
                if len(sqr) != len(set(sqr)):
                    return False
        return True
