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
    
    
ListNode* rev(ListNode* h){
	if(h==NULL){
		return h;
	}
	ListNode* curr = h, *p = NULL, *n = NULL;
	while(curr){
		n = curr->next;
		curr->next = p;
		p = curr;
		curr=n; 
	}
	return p;
}
ListNode* add(ListNode* head1 , ListNode* head2) {
if(head1==NULL)
	return head2;
	if(head2==NULL){
		return head1;
	}
	ListNode* ans = new ListNode(0);
	ListNode* curr =ans;
	int sum = 0, carry = 0;

	while(head1 || head2){
		int x = 0, y=0;
		if(head1){
			x = head1->val;
			head1 = head1->next;
		}

		if(head2){
			y = head2->val;
			head2 = head2->next;
		}

		sum = x+y+carry;
		ListNode* tmp = new ListNode(sum%10);
		carry = sum/10;
		curr->next = tmp;
		curr = curr->next;
	}

	while(carry){
		ListNode* tmp = new ListNode(carry%10);
		carry = carry/10;
		curr->next =tmp;
		curr = curr->next;
	}

	return ans->next;
}
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        head1 = rev(head1);
	head2 = rev(head2);
	return rev(add(head1, head2));

    }
};