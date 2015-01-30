class Solution {
public:
    int numTrees(int n) {
        int treenum[n + 1];
        int numtrees = 0;
        if(n == 0) 
            numtrees = 1;
        else if(n == 1) 
            numtrees = 1;
        else
        {
            treenum[0] = 1;
            treenum[1] = 1;
            for(int i = 2;i <= n; i++)
            {
                treenum[i] = 0;
                for(int j = 0; j < i;j++)
                {
                    treenum[i] += treenum[j] * treenum[i - 1 - j ];
                }
            }
            numtrees = treenum[n];
        }
        return numtrees;
    }
};
