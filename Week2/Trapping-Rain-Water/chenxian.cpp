class Solution {
public:
    int trap(int A[], int n) {
        int sum=0;
        int left=0;
        int right=n-1;
        int lmax=A[left];
        int rmax=A[right];
        
        //由两边向中间按照从小到大顺序依次计算
        while(left<right){
            if(A[left]<A[right]){
                if(A[left]<lmax)
                    sum+=lmax-A[left];
                else
                    lmax=A[left];
                left++;
            }
            else{
                if(A[right]<rmax)
                    sum+=rmax-A[right];
                else
                    rmax=A[right];
                right--;
            }
        }
        return sum;
    }
};
