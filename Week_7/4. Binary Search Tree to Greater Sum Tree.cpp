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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        recur(root, &sum);
        
        return root;
        
    }
    
    void recur (TreeNode* curr, int *prev_sum) {
        
        
        if(curr->right) recur(curr->right, prev_sum);  
        
        *prev_sum = *prev_sum + curr->val;
        curr->val = *prev_sum;
        
        if(curr->left) recur(curr->left, prev_sum);
        
        return;
        
    }
};