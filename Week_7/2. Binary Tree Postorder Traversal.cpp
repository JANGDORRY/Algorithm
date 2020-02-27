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
        
        stack<pair<TreeNode*,int>> s;
        vector <int> ans;
        if(!root) return ans;
        
        pair<TreeNode*, int> curr;
        s.push(make_pair(root,0));
        while(s.size()){
            curr = s.top();
            s.pop();
            
            if(curr.second == 0) {
                curr.second = 1;
                if(curr.first->left) {
                    s.push(curr);
                    s.push(make_pair(curr.first->left,0));
                    continue;
                }
            }
            
            if(curr.second == 1) {
                curr.second = 2;
                if(curr.first->right) {
                    s.push(curr);
                    s.push(make_pair(curr.first->right, 0));
                    continue;
                }
            }
            
            if(curr.second == 2)
                ans.push_back(curr.first->val);
            
        }
        
        return ans;
    }
};