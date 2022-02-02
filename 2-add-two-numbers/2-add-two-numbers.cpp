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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1==NULL)
           return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        int  sum =0, carry = 0;
        
        while(l1 || l2){
            int x = 0, y = 0;
            if(l1){
                x = l1->val;
                l1 = l1->next;
            }
            if(l2){
                y = l2->val;
                l2 = l2->next;
            }
            sum = x+ y + carry;
            carry = sum/10;
            ListNode* tmp = new ListNode(sum%10);
            curr->next = tmp;
            curr = curr->next;
        }
        
        if(carry){
            ListNode* tmp = new ListNode(carry%10);
            carry = carry/10;
            curr->next = tmp;
            curr = curr->next;
        }
        return ans->next;
    }
};