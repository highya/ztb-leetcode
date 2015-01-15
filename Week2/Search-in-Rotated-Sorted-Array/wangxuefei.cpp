class Solution {
public:
    int search(int A[], int n, int target) {
        int first=0,last=n-1;
        while(first<=last)
        {
            int mid = (first + last) / 2;
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[first] <= A[mid])
            {
                if (A[first] <=target && target<= A[mid])
                {
                    last=mid;
                }
                else
                {
                    first=mid+1;
                }
            }
            else
            {
                if (A[mid] <= target && target <= A[last])
                {
                    first=mid+1;
                }
                else
                {
                    last=mid;
                }
            }
        }
        
        return -1;
    }
};
