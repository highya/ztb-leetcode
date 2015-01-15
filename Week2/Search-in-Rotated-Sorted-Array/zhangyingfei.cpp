class Solution {
public:
    int search(int A[], int n, int target) {
        return find(A, 0, n-1, target);
    }
    
    int find(int A[], int l, int r, int t) {
        if(l > r) return -1;
        int mid;
        int idx = -1;
        
        if(A[l] <= A[r]) {
            int left = l, right = r;
            while(left <= right) {
                mid = (left + right) >> 1;
                if(A[mid] == t) {
                    idx = mid;
                    break;
                }
                else if(A[mid] > t) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
        }
        else {
            mid = (l + r) >> 1;
            if(A[mid] == t) {
                idx = mid;
            }
            else {
                idx = find(A, l, mid-1, t);
                if(idx == -1) {
                    idx = find(A, mid+1, r, t);
                }
            }
            
        }
         
        return idx;
    }
    
};
