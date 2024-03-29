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
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL, *tmp =NULL;
        
        while(curr){
            tmp = curr->next;
            curr->next  = prev;
            prev = curr;
            curr = tmp;            
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow=reverse(slow);
        fast = head;
        while(slow){
            if(slow->val!=fast->val)
                return false;
            slow = slow->next;
            fast=fast->next;
        }
        return true;
    }
};