int max3(int a,int b,int c)
{
    int temp = a > b ? a : b;
    return temp > c ?  temp : c;
}
int maxSubSum(int A[],int left,int right)
{
    if(left == right)
    {
       return A[left];
    }
    int center = (left + right) / 2;
    int leftsubsum = maxSubSum(A,left,center);
    int rightsubsum = maxSubSum(A,center + 1,right);
    int leftsum = A[center],leftmaxsum = A[center];
    int rightsum = A[center + 1],rightmaxsum = A[center + 1];
    for(int i = center - 1; i >= left;i--)
    {
        leftsum += A[i];
        if(leftmaxsum < leftsum)
        {
            leftmaxsum = leftsum;
        }
    }
    for(int i = center + 2; i <= right;i++)
    {
        rightsum += A[i];
        if(rightmaxsum < rightsum)
        {
            rightmaxsum = rightsum;
        }
    }
    
    return max3(leftsubsum,rightsubsum,leftmaxsum + rightmaxsum);
}



class Solution {
public:
    int maxSubArray(int A[], int n) {
        return maxSubSum(A,0,n - 1);
    }
};
