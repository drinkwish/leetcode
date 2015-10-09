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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
private:
    void invert(TreeNode* root){
        if(nullptr == root) return;
        
        invert(root->left);
        invert(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        return;
    }
};
