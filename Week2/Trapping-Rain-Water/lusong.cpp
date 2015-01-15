**************************************************************************
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
**************************************************************************

class Solution {
public:
    int trap(int A[], int n) {
        int left = A[0],right = A[n-1];         //左、右边的墙高度
        int i,j;                //循环的步进参数，前后步进
        int water = 0;
        
        if(n == 1) return 0;
        i = 1,j = n-2; 
        while(i <= j){
            if(left <= right){
                if(left > A[i]) water += left - A[i];
                else left = A[i];
                i++;
            }
            if(left > right){
                if(right > A[j]) water += right - A[j];
                else right = A[j];
                j--;
            }
        }
        return water;
        
    }
};
