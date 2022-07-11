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

	void moveList(ListNode*& list, ListNode*& target) {
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
		if (ans->next == nullptr)
			return nullptr;
		cur = ans;
		while (true) {
			if (cur->next->next == nullptr) {
				cur->next = nullptr;
				break;
			}
			cur = cur->next;
		}
		return ans;
    }
};

int main() {

	ListNode* list1 = nullptr;
	ListNode* list2 = nullptr;
	// list1 = new ListNode(4, nullptr);
	// list1 = new ListNode(2, list1);
	// list1 = new ListNode(1, list1);
	// list2 = new ListNode(3, nullptr);
	// list2 = new ListNode(1, list2);
	// list2 = new ListNode(1, list2);
	Solution sol;
	ListNode* ans = sol.mergeTwoLists(list1, list2);
	while (ans != nullptr) {
		cout << ans->val << endl;
		ans = ans->next;
	}
	

	return 0;
}
