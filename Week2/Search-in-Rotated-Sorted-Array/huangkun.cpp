class Solution {
public:
    int binarySearch(int A[],int s,int e,int target){
     if(s<=e){
        int m=(s+e)/2;
        if(A[m]==target)
            return m;
        if(A[m]>target)
            return binarySearch(A,s,m-1,target);
        else
            return binarySearch(A,m+1,e,target);
        }
        return -1;
    }
    int rotatedSearch(int A[],int s, int e,int target){
         if(s<=e){
            int m=(s+e)/2;
            if(A[m]==target)
                return m;
            if(A[s]<=A[m]){
                if(target<A[m] && target>=A[s])
                    return binarySearch(A,s,m-1,target);
                else
                    return rotatedSearch(A,m+1,e,target);
    
            }
            else if(A[e]>=A[m]){
                if(target<=A[e] && target>A[m])
                    return binarySearch(A,m+1,e,target);
                else
                    return rotatedSearch(A,s,m-1,target);
    
            }
            else cout<<"error"<<endl;
    
        }
        return -1;
    }

    int search(int A[], int n, int target) {
        int s=0;
        int e=n-1;
        int index=rotatedSearch(A,s,e,target);
        return index;

    }
};
