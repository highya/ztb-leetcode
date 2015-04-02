class Solution {
public:
vector<vector<int> >res;
vector<int> v;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root==NULL) return res;
        hasPath(root,sum);
        return res;
    }
    void hasPath(TreeNode *root,int sum)
    {
        v.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum==root->val)
            {
                res.push_back(v);
            }
        }
        else
        {
            if(root->left) hasPath(root->left,sum-root->val);
            if(root->right) hasPath(root->right,sum-root->val);
        }
        v.pop_back();
    }
};
