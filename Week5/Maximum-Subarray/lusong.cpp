/***********************************************************************************
Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
***********************************************************************************/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        //f(i): 以第i位结尾的最大子串
        int B[n];
        B[0] = A[0];
        for(int i = 1; i < n; i++)
                B[i] = max(A[i] , B[i-1] + A[i]);
        //求得所有以A[i]结尾的最大子串后，遍历数组B[],求其最大值max
        int max = B[0];
        for(int i = 0; i < n; i++)
            if (B[i] > max) 
                max = B[i];
        return max;
    }
};
