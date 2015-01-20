class Solution {
public:
    bool isValidSubSudoku(vector<vector<char>> &board,int lmin,int lmax,int rmin,int rmax)
    {
        bitset<9> bs;
        size_t num;
        
        for(int i=lmin;i<=lmax;i++) {
            for(int j=rmin;j<=rmax;j++) {
                if(board[i][j] != '.') num = board[i][j] - '1';
                else continue;

                if(bs.test(num)) return false;
                else bs.set(num);
            }
        }
	
	    return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) 
    {
        for(int i=0;i<9;i++) {
            if(!isValidSubSudoku(board,i,i,0,8)) return false;
        }
        
        for(int i=0;i<9;i++) {
            if(!isValidSubSudoku(board,0,8,i,i)) return false;
        }
        
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(!isValidSubSudoku(board,i*3,i*3+2,j*3,j*3+2)) return false;
            }
        }
        
        return true;
    }
};
