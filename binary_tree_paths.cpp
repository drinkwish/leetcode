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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        
        if(nullptr == root) return ret;
        
        string cur = to_string(root->val);
        
        if(nullptr == root->left && nullptr == root->right){
            ret.push_back(cur);
            return ret;
        }
        if(root->left != nullptr) {
            BTP(root->left, ret, cur);
        }
        if(root->right != nullptr){
            BTP(root->right, ret, cur);
        }
        
        return ret;
    }
    
private:
    void BTP(TreeNode* root, vector<string> &ret, string cur){
        cur += "->" + to_string(root->val);
        
        if(nullptr == root->left && nullptr == root->right){
            ret.push_back(cur);
            return;
        }
        if(root->left != nullptr) {
            BTP(root->left, ret, cur);
        }
        if(root->right != nullptr){
            BTP(root->right, ret, cur);
        }
    }
};