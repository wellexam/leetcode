#include "leetcode-list-generator.hpp"
#include "regular_headers.hpp"
#include <iostream>

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    auto head = l1;
    auto cursor = l2;
    if (l2->val < l1->val) {
        swap(head, cursor);
    }
    auto current = head;
    while (current && cursor) {
        if (!current->next) {
            current->next = cursor;
            break;
        }
        if (cursor->val >= current->val) {
            if (cursor->val >= current->next->val) {
                current = current->next;
                continue;
            } else {
                auto temp = current->next;
                current->next = cursor;
                current = current->next;
                cursor = cursor->next;
                current->next = temp;
            }
        }
    }
    return head;
}

int main() {
    auto l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    auto l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    auto head = mergeTwoLists(l1, l2);
    return 0;
}