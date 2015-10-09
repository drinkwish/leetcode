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
    int minDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        
        unsigned left = minDepth(root->left);
        unsigned right = minDepth(root->right);
        
        if(0 == left) return right + 1;
        if(0 == right) return left + 1;
        return left > right ? right + 1 : left + 1;
    }
};