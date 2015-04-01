class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0)  return;
        int length = matrix[0].size(),width = matrix.size();
        bool flag_row = false,flag_column = false;
        for(int i=0;i<width;i++)
            for(int j=0;j<length;j++){
                if(i == 0 || j == 0){
                    if(i == 0 && matrix[i][j] == 0)
                        flag_row = true;
                    if(j == 0 && matrix[i][j] == 0)
                        flag_column = true;
                }
                else if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for(int i=1;i<width;i++)
            for(int j=1;j<length;j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
            }
		if(flag_row)
			for(int i=0;i<length;i++)
				matrix[0][i] = 0;
		if(flag_column)
			for(int i=0;i<width;i++)
				matrix[i][0] = 0;

    }
};
