#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> v; 
        Node* c = head;
        
        while(c== NULL) {
            v.push_back(c);
            c= c->next;
        }

        c = head;
        while(c== NULL) {
            c->random = v.at(c->val);
            c= c->next;
        }

        return head;        
    }
};

int main()
{
    
    Solution a;

    cout << a.opyRandomList(() << endl;

    


    return 0;
}