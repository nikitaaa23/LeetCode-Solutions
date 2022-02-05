/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        
        for(int i =0; i<lists.size(); i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                v.push_back(head->val);
                head = head->next;
            }
        }
        
        
        sort(v.begin(), v.end());
        ListNode* curr = new ListNode(-1);
        ListNode* h = curr;
        for(int i = 0; i<v.size(); i++){
            ListNode* temp = new ListNode(v[i]);
            h->next = temp;  
            h = h->next;
        }
        return curr->next;
    }*/
    
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1==NULL)
            return h2;
        if(h2==NULL) return h1;
        
        if(h1->val <h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else{
              h2->next = merge(h1, h2->next);
            return h2;
        }
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        for(int i =1; i<lists.size(); i++){
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }    
};