class Solution
 {
public:
      Solution()
      {
        point = (int *)malloc(3*sizeof(int));
        sizep = 3;
        point[0] = 1;
        point[1] = 1;
        point[2] = 2;
    }

    ~Solution()
    {
        free(point);
        point = NULL;
        sizep = 0;
    }

    int numTrees(int n)
    {
        if(n <= sizep-1)
        {
            return point[n];
        }

        point = (int *)realloc(point,(n+1)*sizeof(int));
        for(int i=sizep;i<=n;i++)
        {
            point[i] = 0;//初始化新的空间
            
            for(int j=0;j<i;j++)
            {
                point[i]+=point[j]*point[i-j-1];
            }

        }

        return point[n];
    }

private:
    int * point;
    int sizep;
};
