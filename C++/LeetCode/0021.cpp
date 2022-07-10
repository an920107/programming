#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:

	void moveList(ListNode* list, ListNode* target) {
		target->val = list->val;
		target->next = new ListNode();
		target = target->next;
		list = list->next;
	}

public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* cur = new ListNode();
		ListNode* ans = cur;
        while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				moveList(list1, cur);
			}
			else {
				moveList(list2, cur);
			}
		}
		while (list1 != nullptr) {
			moveList(list1, cur);
		}
		while (list2 != nullptr) {
			moveList(list2, cur);
		}
		cur = nullptr;
		return ans;
    }
};

int main() {

	Solution sol;
	

	return 0;
}
