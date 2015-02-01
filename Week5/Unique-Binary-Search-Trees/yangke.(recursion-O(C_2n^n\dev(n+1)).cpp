class Solution {
public:
    int numTrees(int n) {
        if(n==0)return 1;
        else{
            int catalan=0;
            for(int i=1;i<=n;i++)
            {
                catalan+=numTrees(i-1)*numTrees(n-i);
            }
            return catalan;
        }
    }
};
