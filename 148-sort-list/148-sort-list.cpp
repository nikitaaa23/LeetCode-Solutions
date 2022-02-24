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
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
    
        ListNode* ptr = new ListNode(0), *res=ptr;
        
        while(l1 && l2){
            if(l1->val <l2->val){
                res->next = l1;
                l1 = l1->next;
            }
            else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        
        if(l1)
            res->next = l1;
        if(l2)
            res->next = l2;
        
        return ptr->next;
    }
    
    ListNode* mid(ListNode* head){
        ListNode* slow = head, *fast = head, *n = NULL;
        while(fast && fast->next){
            n = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return n;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* m = mid(head);
        ListNode* n = m->next;
        m->next = NULL;
        return merge(sortList(head), sortList(n));
    }
};