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
        
        Node* ans;
        Node* it1 = head;
        Node* it2;
        
        Node *copy;
        copy= new Node(head->val);
        it2 = copy;
        ans = it2;
        
        while(it1->next!= NULL) {
            copy = new Node(it1->next->val);
            it2->next=copy;
            it1 = it1->next;
            it2 = it2->next;
        }


        return head;        
    }
};

int main(){
    
    Solution a;

    //cout << a.copyRandomList() << endl;

    


    return 0;
}