/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void findPath(TreeNode *root, int sum,vector<vector<int>>& result,vector<int>& record){
		if(root == NULL)
            return;
		record.push_back(root->val);
        if(root->left == NULL && root->right==NULL && root->val==sum)
            result.push_back(record);
        findPath(root->left,sum-root->val,result,record);
        findPath(root->right,sum-root->val,result,record);
        record.pop_back();
	}
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        //栈结构        
		vector<vector<int>> result;
        vector<int> record;
		findPath(root,sum,result,record);
        return result;
    }
};
