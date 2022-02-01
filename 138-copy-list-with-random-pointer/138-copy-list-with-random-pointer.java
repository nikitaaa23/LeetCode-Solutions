/*
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
*/

class Solution {
public:
    //O(n), O(n)
   /* Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* ans = head;
        unordered_map<Node*, Node*>mp;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* nHead = NULL;
        
        while(curr){
            Node* n = new Node(curr->val);
            if(!prev) nHead = n;
            else
                prev->next = n;
            prev = n;
            mp[curr] = n;
            curr = curr->next;
        }
        
        curr = head;
        Node* tmp = nHead;
        
        while(curr){
            Node* x = curr->random;
            if(!x) tmp->random = NULL;
            else
                tmp->random = mp[x];
            tmp = tmp->next;
            curr= curr->next;
        }
        return nHead;
    }*/
    
    
    
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* iter = head;
        Node* front = head;
        
        while(iter){
            front = iter->next;
            Node* c = new Node(iter->val);
            iter->next = c;
            c->next = front;
            
            iter = front;
        }
        
        iter = head;
        while(iter){
            if(iter->random !=NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        iter = head;
        Node* p = new Node(0);
        Node* cop = p;
        
        while(iter){
            front = iter->next->next;
            cop->next = iter->next;
            iter->next = front;
            cop = cop->next;
            iter = front;
        }
        
        return p->next;
    }
};