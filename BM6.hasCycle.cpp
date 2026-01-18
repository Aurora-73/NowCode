// Created: 2026-01-18
#include "MyListNode.h"
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/*  */

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(!head) return false;
		ListNode *slow = head, *fast = head->next;
		while(fast && fast->next) {
			if(fast == slow) return true;
			fast = fast->next->next;
			slow = slow->next;
		}
		return false;
	}
};
