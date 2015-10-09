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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        transver(root, 0, ret);
        return ret;
    }
    
private:
    void transver(TreeNode *root, int curHeight, vector<int> &right){
        if(root == nullptr) return;
        
        if(right.size() == curHeight)  right.push_back(root->val);
        
        transver(root->right, curHeight+1, right);
        transver(root->left, curHeight+1, right);
    }
};