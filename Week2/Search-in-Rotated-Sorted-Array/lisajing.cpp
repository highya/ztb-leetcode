class Solution {
public:
    int search(int A[], int n, int target) {
        int i = 0;
        for(; i < n; i++)
        {
            if( target == A[i] )
            return i;
        }
        if(i==n)
            return -1;
        }
};
