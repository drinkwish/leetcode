//52ms, 38.21%

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size() || inorder.size() == 0) return nullptr;
        
        return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int si, int ei, int sp, int ep) {
        if(si == ei) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[ep-1]);
        int i_ = si;
        while(inorder[i_] != postorder[ep-1]){++i_;}
        root->left = buildTree(inorder, postorder, si, i_, sp, sp+i_-si);
        root->right = buildTree(inorder, postorder, i_+1, ei, sp+i_-si,ep-1);
    }
};