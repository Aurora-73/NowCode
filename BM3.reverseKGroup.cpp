// Created: 2026-01-16
#include "MyListNode.h"
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* BM3 链表中的节点每k个一组翻转 */

class Solution {
public:
	/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode dummy(-1), *p = &dummy;
		dummy.next = head;
		while(p) {
			ListNode *part_prev = p, *part_last;
			int i;
			for(i = 0; i < k; ++i) {
				if(!p->next) break;
				p = p->next;
			}
			if(i != k) break;
			part_last = p, p = part_prev->next;
			ListNode *curr = part_prev->next, *prev = nullptr;
			if(part_last) {
				prev = part_last->next;
				part_last->next = nullptr;
			}
			while(curr) {
				ListNode *temp = curr->next;
				curr->next = prev;
				prev = curr;
				curr = temp;
			}
			part_prev->next = prev;
		}
		return dummy.next;
	}
};

int main() {
	Solution sol;
	ListNode *head;
	int k;
	head = createList({ 1, 2, 3, 4, 5 });
	k = 2;
	cout << sol.reverseKGroup(head, k) << endl;

	head = createList({ 1, 2 });
	k = 3;
	cout << sol.reverseKGroup(head, k) << endl;
}