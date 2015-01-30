class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector < vector <int> > total_sum;
        total_sum.clear();
        int size = triangle.size();
        if (size == 0)
            return 0;
        vector <int> tmp;
        tmp.clear();
        tmp.push_back(triangle[0][0]);
        total_sum.push_back(tmp);
        vector <int> sum;
        for(int i = 1;i < size;i++)
        {
            sum.clear();
            for(int j = 0;j < triangle[i].size();j++)
            {
                if( (j == 0))
                    sum.push_back(total_sum[i - 1][j] + triangle[i][j]);
                else if(j == triangle[i].size() - 1) 
                {
                    int prerow = total_sum[i - 1].size();
                    sum.push_back(total_sum[i - 1][prerow - 1] + triangle[i][j]);
                }
                else
                {
                    int mintwo = (total_sum[i - 1][j - 1] + triangle[i][j]) < (total_sum[i - 1][j] + triangle[i][j]) ? (total_sum[i - 1][j - 1] + triangle[i][j]) : (total_sum[i - 1][j] + triangle[i][j]);
                    sum.push_back(mintwo);
                }
            }
            total_sum.push_back(sum);
        }
        sort(total_sum[size - 1].begin(),total_sum[size - 1].end());
        int result = total_sum[size - 1][0];
        return result;
    }
};
