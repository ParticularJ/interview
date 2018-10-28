/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/


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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *guard = new ListNode(0);
		guard->next = head;
		ListNode* pre = guard;
		ListNode* cur = gurad->next;
		// 寻找到真正的pre指针和cur指针
		for (int i = 1; i < m; i++) {
			pre = pre->next;
			cur = cur->next;
		}

		for (int i = 0; i < n - m; i++) {
			// 得到next 
			ListNode* next = cur->next;
			//将cur->next 指向 next->next 
			cur->next = next->next;
			// 将next->next 指向pre->next
			next->next = pre->next;
			// pre-》next 指向next
			pre->next = next;

		}
		return guard->next;
	}
};