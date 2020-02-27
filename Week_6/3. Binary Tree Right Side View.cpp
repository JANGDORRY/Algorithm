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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<int> tmp;
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
            tmp.clear();
            for(int i = 0 ; i < tmp_q_size ; ++i) {
                
                node = q.front();
                q.pop();
                //cout<< node->val << ", ";
                tmp.push_back(node->val);
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                
            }
            
            tmp_last = tmp.at(tmp.size()-1);
            ans.push_back(tmp_last);
            
        }
        
        return ans;
    }
};