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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<TreeNode *> stack;
        deque<TreeNode *> queue;
        
        if(nullptr != root) queue.push_back(root);
        
        while(queue.size()){
            queue.push_back(nullptr);
            while(nullptr != queue.front()){
                if(queue.front()->left) queue.push_back(queue.front()->left);
                if(queue.front()->left) queue.push_back(queue.front()->left);
                stack.push_back(queue.front());
                queue.pop_front();
            }
            stack.push_back(queue.front());
            queue.pop_front();
        }
        
        if(stack.size()) stack.pop_back();
        
        vector<vector<int>> ret;
        while(stack.size()){
            vector<int> tmp;
            while(stack.back()){
                tmp.push_back(stack.back()->val);
                stack.pop_back();
            }
            stack.pop_back();
            ret.push_back(tmp);
        }
        
        return ret;
    }
};