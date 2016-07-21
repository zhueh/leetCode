//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return head;
		}
		ListNode* p = head;
		ListNode* q = head->next;
		while (q != NULL){
			if (p->val == q->val){
				ListNode* t = q;
				p->next = q->next;
				q = q->next;
				delete t;
			}
			else{
				p = q;
				q = q->next;
			}
		}
		return head;
	}
};
//简洁递归版
//
//https ://discuss.leetcode.com/topic/14775/3-line-Java-recursive-solution/2
//[java] view plain copy 在CODE上查看代码片派生到我的代码片
//public ListNode deleteDuplicates(ListNode head) {
//	if (head == null || head.next == null)return head;
//	head.next = deleteDuplicates(head.next);
//	return head.val == head.next.val ? head.next : head;
//}