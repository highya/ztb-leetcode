class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        GetsumPath(result,path,sum,0,root);
        return result;
    }
private:
    void GetsumPath(vector<vector<int> > &result,  
                    vector<int> &path,
                    int sum,
                    int curvalue,
                    TreeNode *root) {
        if(!root) 
            return ;
        curvalue += root->val;
        path.push_back(root->val);
        if(sum == curvalue && root->left == NULL && root->right == NULL ) 
            result.push_back(path);
        
        GetsumPath(result,path,sum,curvalue,root->left);
        GetsumPath(result,path,sum,curvalue,root->right); 
        path.pop_back();
        curvalue -= root->val; 
        return;
    }
};
