// Created: 2026-01-16
#include "MyListNode.h"
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* 合并 k 个升序的链表并将结果作为一个升序的链表返回其头节点。 */

class Solution {
public:
	/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param lists ListNode类vector
     * @return ListNode类
     */
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// write code here
		auto cmp = [](ListNode *l, ListNode *r) {
			return l->val > r->val;
		};
		priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
		for(auto list : lists) {
			if(list) {
				pq.push(list);
			}
		}
		ListNode dummy(-1), *tile = &dummy;
		while(!pq.empty()) {
			tile->next = pq.top();
			pq.pop();
			tile = tile->next;
			if(tile->next) {
				pq.push(tile->next);
			}
		}
		return dummy.next;
	}
};

int main() {
	Solution sol;
	vector<ListNode *> lists;
	lists = { createList({ 1, 2, 3 }), createList({ 4, 5, 6, 7 }) };
	cout << sol.mergeKLists(lists) << endl;
}