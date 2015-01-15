/**
*总的思路是先找到pivot，然后一个数组看成两个分开的数组。
*过程比较繁琐了，不过运行时间还是很快
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 1) return A[0] == target ? 0 : -1;

        int pivot = find_pivot(A, 0, n - 1, n);
        if (A[pivot] < A[pivot + 1]){
            return binary_search(A, 0, n - 1, target);
        }else if (A[pivot] < target || A[pivot + 1] > target){
            return -1;
        }else if (A[0] <= target){
            return binary_search(A, 0, pivot, target);
        }else if (A[pivot] >= target){
            return binary_search(A, pivot + 1, n - 1, target);
        }else{
            return -1;
        }
    }
    
    int find_pivot(int array[], int beg, int end, int n){
        if (end - beg == 1) return beg;
        
        int m = (beg + end) / 2;
        if (array[m] > array[n - 1]){
            return find_pivot(array, m, end, n);
        }else{
            return find_pivot(array, beg, m, n);
        }
    }
    
    int binary_search(int array[], int beg, int end, int target){
        if (beg > end){
            return -1;
        }else if (beg == end){
            if (array[beg] == target){
                return beg;
            }else{
                return -1;
            }
        }
        
        if (array[beg] == target) return beg;
        if (array[end] == target) return end;
        
        int m = (beg + end) / 2;
        if (array[m] == target){
            return m;
        }else if (array[m] < target){
            return binary_search(array, m + 1, end -1, target);
        }else{
            return binary_search(array, beg + 1, m - 1, target);
        }
    }
};
