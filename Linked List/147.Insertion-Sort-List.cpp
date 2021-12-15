class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        ListNode* curr = head;
        ListNode* prev =nHead;
             
        while(curr){
            if(curr->next && curr->next->val < curr->val){
               while(prev->next && prev->next->val < curr->next->val){
                   prev = prev->next;
               }
                
                ListNode* t = prev->next;                
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = t;
                prev = nHead;
            }
            else
                curr = curr->next;
        }
        return nHead->next;
    }
};