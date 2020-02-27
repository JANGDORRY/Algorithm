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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> ans;
        if(root == NULL) return ans;
        
        unordered_map<int,int> umap;
        for(auto it : to_delete){
            umap[it] = 1;
        }
        if(!umap.count(root->val)) ans.push_back(root);
        recur(root, &ans, &umap);
        
        return ans;
        
    }
    
    int recur (TreeNode* curr, vector<TreeNode*>* ans, unordered_map<int,int> *umap) {
        
        int ret = 0;
        
        
        if(curr->right) if(recur(curr->right, ans, umap)) curr->right = NULL;  
        
        if(curr->left) if(recur(curr->left, ans, umap)) curr->left = NULL;

        if(umap->count(curr->val)) {
            if(curr->left) ans->push_back(curr->left);
            if(curr->right) ans->push_back(curr->right);
            ret = 1;
        }
    
        return ret;
        
    }
    
};