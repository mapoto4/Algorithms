/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1, *q = l2；
		ListNode *listNode = new ListNode(0);
		ListNode *T = listNode;
		int carry = 0;
		
		while (p!=NULL||q!=NULL)
		{
			if(p!=NULL)
			{
				carry = carry + p -> val;
				p = p -> next;
			}
			if(q!=NULL)
			{
				carry = carry + q -> val;
				q = q -> next;	
			}
			T -> next = new ListNode ( carry % 10 ); 
			T = T -> next;
			carry = carry / 10;
			
		}
		
		if(carry==1)
            p3 -> next = new ListNode(1);
        return listNode->next;  	
    }
};