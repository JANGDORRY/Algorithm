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
        
        int max = root->val;
        
        int ret = recur(root, &max);
        max = max > ret ? max : ret;
        
        return max;
    }
    
    int recur(TreeNode* one_node, int *max) {
        
        int curr = one_node->val;
        int left_most_sum = one_node->left != NULL ? recur(one_node->left, max) : 0;
        int right_most_sum = one_node->right != NULL ? recur(one_node->right, max) : 0;
        int sum = curr + left_most_sum + right_most_sum;
        sum = sum > curr ? sum : curr;
        *max = *max > sum ? *max : sum;
        int ret = left_most_sum > right_most_sum ? left_most_sum + curr : right_most_sum + curr;
        ret = ret > curr ? ret : curr;
        *max = *max > ret ? *max : ret;
        //cout << ret << " , " << curr << endl;
        return ret;
    }
};