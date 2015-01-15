class Solution {
public:
    int trap(int A[], int n) {
        if(n <= 2)
            return 0;
        vector <int> left(n);
        vector <int> right(n);
        int level = 0;
        for(int i = 0;i < n; i++)
        {
            left[i] = level;
            level = level > A[i] ? level : A[i];
        }
        level = 0;
        for(int i = n-1;i > 0; i--)
        {
            right[i] = level;
            level = level > A[i] ? level : A[i];
        }
        int water_volume = 0;
        int total_volume = 0;
        for(int i = 0; i < n;i++)
        {
            water_volume =  min(left[i],right[i]) - A[i];
            if(water_volume > 0)
            {
                total_volume += water_volume;
            }
        }
        return total_volume;
    }
};

int min(int a,int b)
{
    return (a < b ?  a : b);
}
