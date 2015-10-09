//32ms, 100%

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
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int ret;
        int dist;
        halfPathSum(root, dist, ret);
        return ret;
    }
    
    void halfPathSum(TreeNode* root, int &dist, int &maxi){
        if(root->left == nullptr && root->right == nullptr) {
            dist = root->val;
            maxi  = root->val;
            return;
        }
        
        int dist_right;
        int maxi_right;
        if(root->left == nullptr){
            halfPathSum(root->right, dist_right, maxi_right);
            dist = root->val + max(dist_right, 0);
            maxi = max(maxi_right, dist);
            return;
        }
        
        int dist_left;
        int maxi_left;
        if(root->right == nullptr){
            halfPathSum(root->left, dist_left, maxi_left);
            dist = root->val + max(dist_left, 0);
            maxi = max(maxi_left, dist);
            return;
        }
        
        halfPathSum(root->left, dist_left, maxi_left);
        halfPathSum(root->right, dist_right, maxi_right);
        dist = root->val + max(max(dist_left, dist_right), 0);
        maxi = max(max(maxi_left, maxi_right), max(dist, root->val + dist_left + dist_right));
        return;
    }
};