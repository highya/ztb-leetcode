class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = INT_MIN, i;
        for (i = 0; i < n; ++i){
            if (A[i] > max) max = A[i];
        }
        if (max <= 0) return max;
        
        for (i = 0; i < n; ++i){
            if (A[i] > 0) break;
        }
        max = A[i];
        int cur_max = max;
        for (++i; i < n; ++i){
            cur_max += A[i];
            if (cur_max > max) max = cur_max;
            if (cur_max < 0) cur_max = 0;
        }
        return max;
    }
};
