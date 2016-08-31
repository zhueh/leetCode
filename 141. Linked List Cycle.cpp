//141. Linked List Cycle
//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?
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
	bool hasCycle(ListNode *head) {
		if (head == NULL){ return false; }
		ListNode *low = head;
		ListNode *fast = head->next;
		while (low != NULL && fast != NULL && fast->next != NULL){
			low = low->next;
			fast = fast->next->next;
			if (low == fast){
				return true;
			}
		}
		return false;
	}
};