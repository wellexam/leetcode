#include "leetcode-list-generator.hpp"
#include "regular_headers.hpp"
#include <iostream>

using namespace std;

ListNode *merge(ListNode *first, ListNode *second, ListNode *end) {
    auto new_start = first;
    auto second_flag = second;
    if (first != second_flag && second != end) {
        if (second->val < first->val) {
            auto temp = second->next;
            second->next = first;
            first = second;
            second = temp;
            new_start = first;
        }
    }
    while (first->next != second_flag && second != end) {
        if (second->val <= first->next->val) {
            auto f_next = first->next, s_next = second->next;
            first->next = second;
            second->next = f_next;
            second = s_next;
            first = first->next;
        } else {
            first = first->next;
        }
    }
    if (second != end) {
        first->next = second;
    } else {
        while (first->next != second_flag) {
            first = first->next;
        }
        first->next = end;
    }
    return new_start;
}

ListNode *sortlist(ListNode *start, ListNode *end) {
    if (start->next == end || start->next->next == end) {
        return start;
    }
    ListNode *mid, *last;
    mid = start;
    last = start;
    while (last->next != end) {
        last = last->next;
        if (last->next != end) {
            last = last->next;
        }
        if (mid->next != end) {
            mid = mid->next;
        }
    }
    start = sortlist(start, mid);
    mid = sortlist(mid, end);
    start = merge(start, mid, end);
    return start;
}

ListNode *sortList(ListNode *head) {
    ListNode *mid = head, *last = head;
    while (last->next) {
        last = last->next;
        if (last->next) {
            last = last->next;
        }
        if (mid->next) {
            mid = mid->next;
        }
    }
    head = sortlist(head, mid);
    mid = sortlist(mid, nullptr);
    head = merge(head, mid, nullptr);
    return head;
}

int main() {
    auto head = list_generator({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    // auto head = list_generator({4, 3, 2, 1});
    head = sortList(head);
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
}