//0ms, 100%

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        
        TreeNode* p = root;
        deque<TreeNode *> _stack;
        _stack.push_back(p);
        while(_stack.size()){
            p = _stack.back();
            ret.push_back(p->val);
            _stack.pop_back();
            
            if(p->right) _stack.push_back(p->right);
            if(p->left) _stack.push_back(p->left);
        }
        
        return ret;
    }
};