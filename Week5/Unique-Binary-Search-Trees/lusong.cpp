 /*********************************************************
Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*********************************************************/   
思路：        
        //一颗n个节点的树，除掉根节点，左右子树总和为（n-1）个。设f（n）表示：n个节点有f（n）个BST树。
        //则：f（n）= Σ f（Ln）*f（Rn），Ln + Rn = n-1。 Ln、Rn∈[0，n-1]
class Solution {
public:
    int numTrees(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        //初始化，让treenum[0] 为1，方便后面的乘法计算。真正返回的是treenum[n]；treenum[0]不要它。
        int treenum[n+1] = {1,1,2};

        for(int i = 3; i < n+1; i++)
            for(int j = 0; j < i; j++){
                treenum[i] += treenum[j] * treenum[i-1-j];
            }
        return treenum[n];        
    }
};
