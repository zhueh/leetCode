//24. Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.
//
//Subscribe to see which companies asked this question

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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL){ return head; }
		ListNode *temp = NULL;
		temp = head;
		head = head->next;
		head->next = temp;
		if (temp->next->next == NULL || temp->next->next->next == NULL){
			head->next->next = temp->next->next;
		}
		else{
			head->next->next = temp->next->next->next;
		}
		swapPairs(head->next->next);
		return head;
	}
};