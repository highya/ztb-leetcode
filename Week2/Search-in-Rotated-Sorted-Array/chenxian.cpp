class Solution {
public:
    int search(int A[], int n, int target) {
        int low=0;
        int high=n-1;
        int mid;
        int fix=10000;  //加一个修正值使得数组保持递增。
        int temp=0;
        int target2=target<A[0]?target+fix:target;
        
        //2分查找
        while(low+1<high){
            mid=(low+high)/2;
            if(A[mid]<A[0])
                temp=A[mid]+fix;
            else
                temp=A[mid];
            if(temp==target2)
                break;
            else if(temp<target2)
                low=mid;
            else
                high=mid;
        }
        if(A[mid]==target)
            return mid;
        else if(A[low]==target)
            return low;
        else if(A[high]==target)
            return high;
        else
            return -1;
    }
};
