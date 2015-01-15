class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int SIZE = 9;
        vector<vector<bool> > x;
        vector<vector<bool> > y;
        vector<vector<bool> > z;
        initial(x);
        initial(y);
        initial(z);
        for (int i = 0; i < SIZE; ++i){
            for (int j = 0; j < SIZE; ++j){
                if (board[i][j] == '.') continue;
                
                int index = board[i][j] - '1';
                if (y[i][index] == true)
                    return false;
                else
                    y[i][index] = true;
                    
                if (x[j][index] == true)
                    return false;
                else
                    x[j][index] = true;
                    
                int z_i = z_index(i, j);
                if (z[z_i][index] == true)
                    return false;
                else
                    z[z_i][index] = true;
            }
        }
        return true;
    }
    
    void initial(vector<vector<bool> > &m){
        vector<bool> tmp(9, false);
        for (int i = 0; i < 9; ++i) m.push_back(tmp);
    }
    
    int z_index(int i, int j){
        i = i / 3 + 1;
        j = j / 3 + 1;
        return j + (i - 1) * 3 - 1;
    }
};
