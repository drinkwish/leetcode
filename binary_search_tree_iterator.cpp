//12ms, 79.15%

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *tmp = root;
        while(tmp){
            _stack.push_back(tmp);
            tmp = tmp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _stack.size() != 0;
    }

    /** @return the next smallest number */
    int next() {
            TreeNode *tmp = _stack.back();
            _stack.pop_back();
            int ret = tmp->val;
            tmp = tmp->right;
            while(tmp != nullptr){
                _stack.push_back(tmp);
                tmp = tmp->left;
            }
        
            return ret;
    }
    
private:
    list<TreeNode *> _stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */