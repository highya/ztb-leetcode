class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==0) return -1;
        
        int l=0,r=n-1,m=n/2;
        int b;
        
        while(r-l>1)
        {
            if(A[m]==target) return m;
            
            if( A[m]<min(A[r],A[l])&&target>=max(A[r],A[l]) ) {
                b=0;
            }
            else if( A[m]>max(A[r],A[l])&&target<=min(A[r],A[l]) ) {
                b=1;
            }
            else if(target<A[m]) {
                b=0;
            }
            else if(A[m]==A[r]){
                b=0;
            }
            else b=1;
            
            if(b==0) r=m-1;
            else l=m+1;

            m=(l+r)/2;
        }
        
        if(A[l]==target) return l;
        if(A[r]==target) return r;
        else return -1;
    }
};
