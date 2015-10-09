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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        
        deque<pair<TreeNode*, bool>>_stack;
        TreeNode* p = root;
        
        while(_stack.size() || p != nullptr){
            while(p != nullptr){
                _stack.push_back(pair<TreeNode*, bool>(p,false));
                p = p->left;
            }
            
            p = _stack.back().first;
            if(_stack.back().second || p->right == nullptr){
                ret.push_back(p->val);
                p = nullptr;
                _stack.pop_back();
            }else{
                _stack.pop_back();
                _stack.push_back(pair<TreeNode*, bool>(p, true));
                p = p->right;
            }
        }
        
        return ret;
    }
};