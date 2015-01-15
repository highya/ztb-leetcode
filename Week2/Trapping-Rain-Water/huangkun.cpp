class Solution {
public:
    int trap(int A[], int n) {
        int maxVal=-1;
        int maxValIndex=-1;
        int water=0;
        int curMaxVal=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>maxVal)
            {
                maxVal=A[i];
                maxValIndex=i;
            }    
        }
        curMaxVal=A[0];
        for(int i=1;i<maxValIndex;i++)
        {
            if(A[i]<curMaxVal)
            {
                water+=curMaxVal-A[i];
            }
            else 
                curMaxVal=A[i];
    
        }
        curMaxVal=A[n-1];
        for(int j=n-2;j>maxValIndex;j--)
        {
            if(A[j]<curMaxVal)
            {
                water+=curMaxVal-A[j];
            }
            else
                curMaxVal=A[j];
        }
        return water;
    }
};
