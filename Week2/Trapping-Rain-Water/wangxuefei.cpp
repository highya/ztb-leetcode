class Solution {
public:
    int trap(int A[], int n) {
        vector<int> maxl(n);
		vector<int> maxr(n);
        
        for (int i = 0; i < n; ++i) {
            maxl[i] = max(A[i], i == 0 ? 0 : maxl[i - 1]);
        }
        for (int i = n - 1; i >= 0; --i) {
            maxr[i] = max(A[i], i == n - 1 ? 0 : maxr[i + 1]);
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(maxl[i], maxr[i]) - A[i];
        }
        
        return res;
    }
};
