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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL){ return l2; }
		if (l2 == NULL){ return l1; }
		ListNode *head = NULL;
		if (l1->val < l2->val){
			head = l1;
			l1 = l1->next;
		}
		else{
			head = l2;
			l2 = l2->next;
		}
		ListNode *l3 = head;
		while (l1 != NULL && l2 != NULL){
			if (l1->val <= l2->val){
				l3->next = l1;
				l1 = l1->next;
			}
			else{
				l3->next = l2;
				l2 = l2->next;
			}
			l3 = l3->next;

		}
		if (l1 == NULL){
			l3->next = l2;
		}
		if (l2 == NULL){
			l3->next = l1;
		}
		return head;
	}
};

//recursion
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}
};