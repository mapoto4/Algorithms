/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
		if(head==null||head.next ==null)
			return head;
		
		ListNode fh = new ListNode();
		fh.next = head;
		
		ListNode ptr1 = fh;
		ListNode ptr2 = head;
		
		while(ptr2!=null && ptr2.next != null){
			ListNode ns = ptr2.next.next;
			ptr2.next.next = ptr2;
			ptr1.next = ptr2.next;
			ptr2.next = ns;
			ptr1 = ptr2;
			ptr2 = ptr2.next;
		}
		return fh.next;
    }
}