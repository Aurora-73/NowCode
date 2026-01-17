// Created: 2026-01-17
#include "MyListNode.h"
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* 描述
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6} */

class Solution {
public:
	/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
	ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
		ListNode dummy(0), *tile = &dummy;
		while(pHead1 && pHead2) {
			if(pHead1->val < pHead2->val) {
				tile->next = pHead1;
				tile = tile->next;
				pHead1 = pHead1->next;
			} else {
				tile->next = pHead2;
				tile = tile->next;
				pHead2 = pHead2->next;
			}
		}
		if(pHead1) tile->next = pHead1;
		if(pHead2) tile->next = pHead2;
		return dummy.next;
	}
};

int main() {
	Solution sol;
	ListNode *head1, *head2;
	head1 = createList({ 1, 3, 5 });
	head2 = createList({ 2, 4, 6 });
	cout << sol.Merge(head1, head2) << endl;
}