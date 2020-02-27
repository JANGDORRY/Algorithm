/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        
        Node* curr_node = root;
        Node* next_node;
        
        if(root == NULL) return root;
        
        while(curr_node != NULL) {
            next_node = curr_node;
            
            while(next_node && next_node->left) {
                next_node->left->next = next_node->right;
                if(next_node->next) next_node->right->next = next_node->next->left;
                next_node = next_node->next;
                
            }
            
            curr_node = curr_node->left;
        }
    
        
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        
        
        vector<int> tmp;
        queue<Node*> q;
        int tmp_q_size;
        Node* node;
        Node* prev_node;
        int tmp_last;
        
        if(root == NULL) {
            //ans.push_back(tmp);
            return root;
        }
    
        q.push(root);
        
        while(q.size()!=0){
            
            tmp_q_size = q.size();
            prev_node = NULL;
            for(int i = 0 ; i < tmp_q_size ; ++i) {
                
                node = q.front();
                q.pop();
                if(prev_node!= NULL)
                    prev_node->next = node;
                
                prev_node = node;
                
                if(node->left != NULL)
                    q.push(node->left);
                
                    
                if(node->right != NULL)
                    q.push(node->right);
                
            }
            
        }
        
        return root;
    }
};