class Solution {
public:
    int trap(int A[], int n) {
        int left = 0, right = n-1;
        int maxleft = A[left], maxright = A[right];
        int trap_area = 0;
        while(left <= right) {
            if(maxleft < maxright) {
                if(maxleft < A[left]) maxleft = A[left];
                trap_area += maxleft - A[left];
                left++;
            }
            else {
                if(maxright < A[right]) maxright = A[right];
                trap_area += maxright - A[right];
                right--;
            }
        }
        return trap_area;
    }
};
