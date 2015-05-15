class Solution {
public:
    vector<int> start_pt;
    int n,m;
    
    void check(int x,int y,vector<vector<char>>& board){
        if((x<0)||(x>m-1)||(y<0)||(y>n-1))
            return;
        if(board[x][y]=='O'){
            start_pt.push_back(x*n+y);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        m=board.size();
        if(m==0)
            return;
        n=board[0].size();
        if(n==0)
            return;

        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
                start_pt.push_back(j);
            if(board[m-1][j]=='O')
                start_pt.push_back((m-1)*n+j);
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O')
                start_pt.push_back(i*n);
            if(board[i][n-1]=='O')
                start_pt.push_back(i*n+n-1);
        }
        
        for(int i=0;i<start_pt.size();i++){
            int index=start_pt[i];
            int x=index/n;
            int y=index%n;
            if(board[x][y]!='V'){
                board[x][y]='V';
                check(x-1,y,board);
                check(x+1,y,board);
                check(x,y-1,board);
                check(x,y+1,board);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='V')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};
