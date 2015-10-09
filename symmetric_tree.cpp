//4ms, fast enough

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricSame(root, root);
        
    }
    
private:
    bool isSymmetricSame(TreeNode * p, TreeNode *q){
        if(p == q && nullptr == p) return true;
        
        if(nullptr == p || nullptr == q || p->val != q->val) return false;
        
        return isSymmetricSame(p->left, q->right) && isSymmetricSame(p->right, q->left);
    }
};