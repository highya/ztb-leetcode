class Solution {
public:
	int check(int i,int j,int& sum,vector<vector<char> > &board){
    	if(board[i][j] == '.')
			return 1;
    	else if((sum & (1 << (board[i][j]-'0'))) == 0){
    		sum = sum + (1 << (board[i][j]-'0'));
			return 1;
    	}
    	else
			return 0;
	}
    bool isValidSudoku(vector<vector<char> > &board) {
        int i=0,j=0,i1=0,j1=0;
        //对于每一行
        for(i=0;i<9;i++){
            int sum = 0;
            for(j=0;j<9;j++)
				if(check(i,j,sum,board) == 0)
					return false;
        }
        //对于每一列
        for(j=0;j<9;j++){
            int sum = 0;
            for(i=0;i<9;i++)
				if(check(i,j,sum,board) == 0)
					return false;
        }
        //对于每一个格
        for(i=0;i<3;i++)
            for(j=0;j<3;j++){
                int sum = 0;
                for(i1=i*3;i1<i*3+3;i1++)
                    for(j1=j*3;j1<j*3+3;j1++){ 
						if(check(i1,j1,sum,board) == 0)
							return false;
                    }
            }
        return true;
    }
};
