class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];
        vector<int> last(n);
        vector<int> current(n);
        last[0] = triangle[0][0];
        
        for (int i = 1; i < n; ++i){
            for (int j = 0; j <= i; ++j){
                int left = j > 0 ? last[j - 1] : INT_MAX;
                int right = j < i ? last[j] : INT_MAX;
                int min = left < right ? left : right;
                current[j] = min + triangle[i][j];
            }
            for (int j = 0; j <= i; ++j){
                last[j] = current[j];
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < n; ++i){
            if (current[i] < result) result = current[i];
        }
        return result;
    }
};
