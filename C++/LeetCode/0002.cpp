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
    void __add(ListNode* l1, ListNode* l2, ListNode* result) {
        if (l1 == nullptr && l2 == nullptr) return;

        int val1 = l1 == nullptr ? 0 : l1->val;
        int val2 = l2 == nullptr ? 0 : l2->val;
        result->val += val1 + val2;
        result->next = new ListNode(result->val / 10);
        result->val %= 10;

        ListNode* next1 = l1 == nullptr ? nullptr : l1->next;
        ListNode* next2 = l2 == nullptr ? nullptr : l2->next;
        __add(next1, next2, result->next);
    }

    void __removeTailZero(ListNode* l) {
        if (l == nullptr || l->next == nullptr) return;
        if (l->next->next == nullptr) {
            if (l->next->val == 0) {
                l->next = nullptr;
            }
        }
        __removeTailZero(l->next);
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        __add(l1, l2, result);
        __removeTailZero(result);
        return result;
    }
};