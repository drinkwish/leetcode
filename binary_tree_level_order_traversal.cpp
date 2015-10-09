//8ms, can be optimized

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(nullptr == root) return ret;
        
        deque<TreeNode *> q;
        
        
        q.push_back(root);
        while(q.size() != 0){
            q.push_back(nullptr);
            vector<int> tmp;
            
            while(q.front() != nullptr){
                tmp.push_back(q.front()->val);
                if(q.front()->left != nullptr)  q.push_back(q.front()->left);
                if(q.front()->right != nullptr) q.push_back(q.front()->right);
                q.pop_front();
            }
            ret.push_back(tmp);
            q.pop_front();
        }
        
        return ret;
        
    }
};