// Created: 2026-01-16
#include "MyListNode.h"
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* BM1 反转链表描述

给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。
如当输入链表{1,2,3}时，
经反转后，原链表变为{3,2,1}，所以对应的输出为{3,2,1}。 */

class Solution {
public:
	/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param head ListNode类 
     * @return ListNode类
     */
	ListNode *ReverseList(ListNode *head) {
		ListNode *prev = nullptr, *curr = head;
		while(curr) {
			ListNode *temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		return prev;
	}
};

int main() {
	Solution sol;
	ListNode *head;
	head = createList({ 1, 2, 3, 4 });
	cout << sol.ReverseList(head) << endl;
}