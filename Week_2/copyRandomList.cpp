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
        if(head == NULL) return NULL;
        vector<Node*> save;
        Node* ans;
        Node* it1 = head;
        Node* it2;
        Node* it3;
        
        Node *copy;
        copy= new Node(head->val);
        it2 = copy;
        ans = it2;
        save.push_back(copy);
        int m_c = 1;
        
        while(it1->next!= NULL) {
            copy = new Node(it1->next->val);
            it2->next=copy;
            save.push_back(copy);
            it1 = it1->next;
            it2 = it2->next;
            m_c++;
        }
        
        it1= head;
        it2= ans;
        
        
        while(it1!=NULL) {
            it3= it1->random;
            int c = 0;
            while(it3!=NULL) {
                c++;
                it3 = it3->next;
            }
            it3 = ans;
            for(int i = 0 ; i < (m_c-c) ;++i) {
                it3 = it3->next;
            }
            it2->random = it3;
            it1 = it1->next;
            it2 = it2->next;
            
        }
        
        return ans;
        
        
    }
};

int main(){
    
    Solution a;

    //cout << a.copyRandomList() << endl;

    


    return 0;
}