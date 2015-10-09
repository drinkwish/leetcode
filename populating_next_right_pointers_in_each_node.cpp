//28ms, 9.28%

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root){
            deque<TreeLinkNode*> _stack;
            _stack.push_back(root);
            _stack.push_back(nullptr);
            
            while(_stack.size()>1){
                TreeLinkNode* tmp = _stack.front();
                _stack.pop_front();
                if(tmp){
                    if(tmp->left) _stack.push_back(tmp->left);
                    if(tmp->right) _stack.push_back(tmp->right);
                    tmp->next = _stack.front();
                }
                else _stack.push_back(tmp);
            }
        }
    }
};