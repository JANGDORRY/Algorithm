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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans = NULL;
        if(root == NULL) return ans;
      
        int ret = recur(root, p, q, &ans);
        if (ret == 2 && ans == NULL) ans = root;

        
        return ans;
        
    }
    
    int recur (TreeNode* curr, TreeNode* p, TreeNode* q, TreeNode** ans) {
        
        int ret = 0; 
        
        if(curr->left)  ret = ret + recur(curr->left, p, q, ans);        
        if(curr->right) ret = ret + recur(curr->right, p, q, ans);

        if(curr->val == p->val || curr->val == q->val) ret = ret + 1;
        
        if (ret == 2 && *ans == NULL) *ans = curr;
        
        return ret;
    }
};