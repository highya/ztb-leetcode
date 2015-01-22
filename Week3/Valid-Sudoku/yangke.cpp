class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if(checkRow(board)&&checkCol(board)&&checkBlocks(board))
        {
            return true;
        }
        return false;
        
    }
    bool checkBlocks(vector<vector<char> > &board) 
    {
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                if(!checkB(board,i,j))
                    return false;
            }
        }
        return true;
    }
    bool checkB(vector<vector<char> > &board,int m,int n)
    {
        map<char,bool> mp;
        for(int i=m;i<m+3;i++)
        {
            for(int j=n;j<n+3;j++)
            {
                if (board[i][j]!='.'){
                    if(mp[board[i][j]])
                    {
                        return false;
                    }else{
                        mp[board[i][j]]=true;
                    }
                }
            }
        }
        mp.clear();
        return true;
    }
    bool checkCol(vector<vector<char> > &board) 
    {
        for(int j=0;j<9;j++)
        {
            map<char,bool> mp;
            for(int i=0;i<9;i++)
            {
                if (board[i][j]!='.'){
                    if(mp[board[i][j]])
                    {
                        return false;
                    }else{
                        mp[board[i][j]]=true;
                    }
                }
            }
            mp.clear();
        }
        return true;
    }
    bool checkRow(vector<vector<char> > &board)
    {
        for(int i=0;i<9;i++)
        {
            map<char,bool> mp;
            for(int j=0;j<9;j++)
            {
                if (board[i][j]!='.'){
                    if(mp[board[i][j]])
                    {
                        return false;
                    }else{
                        mp[board[i][j]]=true;
                    }
                }
            }
            mp.clear();
        }
        return true;
    }
};
