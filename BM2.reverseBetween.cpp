// Created: 2026-01-16
#include "MyListNode.h"
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* 将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度  */

class Solution {
public:
	/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode dummy(0), *res_prev, *end = &dummy;
		dummy.next = head;
		for(int i = 0; i < n; ++i) {
			if(i == m - 1) {
				res_prev = end;
			}
			end = end->next;
		}
		ListNode *curr = res_prev->next, *prev = end->next;
		res_prev->next = nullptr;
		end->next = nullptr;
		while(curr) {
			ListNode *temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		res_prev->next = prev;
		return dummy.next;
	}
};

int main() {
	Solution sol;
	ListNode *head = createList({ 1, 2, 3, 4, 5 });
	int m = 2, n = 4;
	cout << sol.reverseBetween(head, m, n) << endl;
}