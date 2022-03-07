#include "leetcode-list-generator.hpp"
#include "regular_headers.hpp"
#include <iostream>

using namespace std;

void print(ListNode *head) {
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

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

ListNode *sortList(ListNode *head, ListNode *tail) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }
    auto fast = head, slow = head;
    while (fast != tail) {
        fast = fast->next;
        slow = slow->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    auto mid = slow;
    head = mergeTwoLists(sortList(head, mid), sortList(mid, tail));
    return head;
}

ListNode *sortList(ListNode *head) {
    return sortList(head, nullptr);
}

int main() {
    auto head = list_generator({5, 4, 3, 2, 1});
    // auto head = list_generator({4, 3, 2, 1});
    head = sortList(head);
    print(head);
}