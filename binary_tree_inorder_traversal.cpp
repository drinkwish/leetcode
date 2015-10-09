//0ms, fast enough

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        
        TreeNode *p = root;
        deque<TreeNode *> _stack;
        
        while(p != nullptr || _stack.size()){
            while(p!= nullptr){
                _stack.push_back(p);
                p = p->left;
            }
            
            p = _stack.back();
            ret.push_back(p->val);
            _stack.pop_back();
            p = p->right;
        }
        
        return ret;
    }
};