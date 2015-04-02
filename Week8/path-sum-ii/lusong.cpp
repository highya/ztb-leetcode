class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root,sum,0);
    }
private:
    bool dfs(TreeNode *node, int sum, int cursum) {
        if(!node) 
            return false;
        if(node->left == NULL && node->right == NULL) {
            return sum == node->val + cursum;
        }
        return dfs(node->left,sum,node->val + cursum) || dfs(node->right,sum,node->val + cursum);
    }
};
