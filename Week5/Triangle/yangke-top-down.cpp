class Solution {  
public:  
    int minimumTotal(vector<vector<int> > &triangle) { 
        int n = triangle.size();  
        if(n == 0) return 0;  
        vector<int> f(n+1, INT_MAX);  
        for(int m = 1; m <= n; ++m)  
        {  
            for(int j = m; j >= 1; --j)  
            {  
                if(m == 1 && j == 1) f[j] = triangle[m-1][j-1];  
                else f[j] = min(f[j], f[j-1])+triangle[m-1][j-1];  
            }  
        }  
          
        int mmin = INT_MAX;  
        for(int j = 1; j <= n; ++j) mmin = min(f[j], mmin);  
          
        return mmin;  
    }  
};
