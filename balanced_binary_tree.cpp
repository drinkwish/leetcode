//12ms, fast enough

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
    bool isBalanced(TreeNode* root) {
        if(nullptr == root) return true;
        
        int left = treeDepth(root->left);
        if(left == -1) return false;
        
        int right = treeDepth(root->right);
        if(right == -1) return false;
        
        if(left - right < -1 || left - right > 1) return false;
        
        return true;
    }
    
private:
    int treeDepth(TreeNode* root){
        if(nullptr == root) return 0;
        
        int left = treeDepth(root->left);
        if(left == -1) return -1;
        int right = treeDepth(root->right);
        if(right == -1) return -1;
        
        if(left - right < -1 || left - right > 1) return -1;
        
        return left > right ? left + 1 : right + 1;
    }
    
};