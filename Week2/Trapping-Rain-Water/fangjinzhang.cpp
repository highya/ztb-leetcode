/*
*唉，这道题又是想太多。。想太多了。。。
*人品还不错，运行很快，12ms
*/
struct b_tree{//二叉查找树
    b_tree(int ph, int pi):h(ph), i(pi), left(NULL), right:(NULL){}
    int h;
    int i;
    b_tree *left;
    b_tree *right;
};

class Solution {
public:
    int trap(int A[], int n) {
        int *a = new int[n + 2];
        a[0] = a[n + 1] = 0;
        for (int i = 0; i < n; ++i) a[i + 1] = A[i];
        n = n + 2;
        
        bool isUp = true;
        b_tree *tree = NULL;
        for (int i = 0; i < n - 1; ++i){
            if (isUp == true){
                if (a[i] <= a[i + 1]){
                    continue;
                }else{
                    isUp = false;
                    b_tree *node = new b_tree(a[i], i);
                    insert_tree(tree, node);
                }
            }else {
                if (a[i] >= a[i + 1]){
                    continue;
                }else{
                    isUp = true;
                }
            }
        }
        
        vector<b_tree *> tops;
        build_vector(tree, tops);
        if (tops.size() < 2) return 0;
        
        int left, right;
        if (tops[0]->i < tops[1]->i){
            left = tops[0]->i;
            right = tops[1]->i;
        }else{
            left = tops[1]->i;
            right = tops[0]->i;
        }
        
        int result = cal(a, left, right, tops[1]->h);
        for (int i = 2; i < tops.size(); ++i){
            int index = tops[i]->i;
            if (index > right){
                result += cal(a, right, index, tops[i]->h);
                right = index;
            }else if (index < left){
                result += cal(a, index, left, tops[i]->h);
                left = index;
            }else{
                continue;
            }
        }
        
        return result;
    }
    
    int cal(int a[], int left, int right, int h){
        int ret = 0;
        for (int i = left + 1; i <= right -1; ++i){
            if (a[i] >= h) continue;
            ret += h - a[i];
        }
        return ret;
    }
    
    void insert_tree(b_tree *&tree, b_tree *node){
        if (tree == NULL) {
            tree = node;
        }else if (tree->h < node->h){
            insert_tree(tree->right, node);
        }else {
            insert_tree(tree->left, node);
        }
    }
    
    void build_vector(b_tree *tree, vector<b_tree *> &tops){
        if (tree == NULL) return;
        
        if (tree->right != NULL){
            build_vector(tree->right, tops);
            tops.push_back(tree);
            build_vector(tree->left, tops);
        }else {
            tops.push_back(tree);
            build_vector(tree->left, tops);
        }
    }
};
