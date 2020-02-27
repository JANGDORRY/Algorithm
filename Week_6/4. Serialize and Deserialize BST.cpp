/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
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
            for(int i = 0 ; i < tmp_q_size ; ++i) {
                
                node = q.front();
                q.pop();
                //cout<< node->val << ", ";
                ans.push_back(node->val);
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                
            }
            
            
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));