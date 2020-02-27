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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        int val;
        queue<TreeNode*> q;
        int tmp_q_size;
        TreeNode* node;
        int tmp_last;
        
        if(root == NULL) {
            //ans.push_back(tmp);
            return ans;
        }
    
        q.push(root);
        
        while(q.size()!=0){
            
            tmp_q_size = q.size();
            for(int i = 0 ; i < tmp_q_size ; ++i) {
                
                node = q.front();
                q.pop();
                //cout<< node->val << ", ";
                val = node->val;
                if (L <= val && val <= R) 
                    ans = ans + val;
                
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                
            }
                       
        }
        return ans;
    }
};