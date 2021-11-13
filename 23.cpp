#include "regular_headers.hpp"

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
        if (l1) {
            return l1;
        }
        if (l2) {
            return l2;
        }
        return nullptr;
    }
    auto new_start = l1;
    if (l1 && l2) {
        if (l2->val < l1->val) {
            auto temp = l2->next;
            l2->next = l1;
            l1 = l2;
            l2 = temp;
            new_start = l1;
        }
    }
    while (l1->next && l2) {
        if (l2->val <= l1->next->val) {
            auto f_next = l1->next, s_next = l2->next;
            l1->next = l2;
            l2->next = f_next;
            l2 = s_next;
            l1 = l1->next;
        } else {
            l1 = l1->next;
        }
    }
    if (l2) {
        l1->next = l2;
    } else {
        while (l1->next) {
            l1 = l1->next;
        }
        l1->next = nullptr;
    }
    return new_start;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
        return nullptr;
    }
    int size = lists.size();
    for (int step = 1; step < size; step *= 2) {
        int current = 0;
        while (current + step < size) {
            lists[current] = mergeTwoLists(lists[current], lists[current + step]);
            current += 2 * step;
        }
    }
    return lists.front();
}