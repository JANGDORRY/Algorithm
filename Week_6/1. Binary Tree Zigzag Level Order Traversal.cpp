// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<int>tmp;
        queue<TreeNode*> q;
        int tmp_q_size;
        TreeNode* node;
        int flag = 0;
        
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
            //cout << endl;
            if(flag) {
                reverse(tmp.begin(), tmp.end());
            } 
            ans.push_back(tmp);
            flag = flag ^ 1;
        }
        
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
//         vector<vector<int>> ans;
//         vector<int>tmp;
//         vector<TreeNode*> q;
//         TreeNode* node;

//         int curr_q_size = -1;
//         int prev_q_size = 0;
//         int flag = 0;
        
//         if(root == NULL) {
//             //ans.push_back(tmp);
//             return ans;
//         }
    
//         q.push_back(root);
//         curr_q_size = q.size();
        
//         while(curr_q_size != prev_q_size){
            
//             tmp.clear();
//             for(int i = 0 ; i < curr_q_size - prev_q_size ; ++i) {
                               
//                 if(flag) {
                    
//                     node = q[prev_q_size + i];
//                     cout<< node->val << ", ";
//                     tmp.push_back(node->val);                    
//                     if(node->left != NULL)
//                         q.push_back(node->left);
//                     if(node->right != NULL)
//                         q.push_back(node->right);
//                 } else {         
                    
//                     node = q[curr_q_size - i -1];
//                     cout<< node->val << ", ";
//                     tmp.push_back(node->val);
//                     if(node->right != NULL)
//                         q.push_back(node->right);
//                     if(node->left != NULL)
//                         q.push_back(node->left);
//                 }
            
                
//             }
//             //cout << endl;
            
//             ans.push_back(tmp);
//             flag = flag ^ 1;
//             prev_q_size = curr_q_size;
//             curr_q_size = q.size();
//         }
        
//         return ans;
//     }
// };