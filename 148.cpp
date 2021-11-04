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

ListNode *merge(ListNode *l1, ListNode *l2, ListNode *&tail) {
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
        while (l2->next) {
            l2 = l2->next;
        }
        tail = l2;
    } else {
        while (l1->next) {
            l1 = l1->next;
        }
        l1->next = nullptr;
        tail = l1;
    }
    return new_start;
}

ListNode *split(ListNode *head, int n) {
    while (head->next && --n) {
        head = head->next;
    }
    auto new_head = head->next;
    head->next = nullptr;
    return new_head;
}

ListNode *sortList(ListNode *head) {
    if (!head) {
        return head;
    }
    auto temp = head;
    int count = 1;
    while (temp->next) {
        temp = temp->next;
        ++count;
    }
    auto current_head = head;
    int n = 1;
    auto current_head = head;
    while (n / 2 < count) {
        while (current_head) {
            auto second_head = split(current_head, n);
            if (!second_head) {
                
            }
            auto next_head = split(second_head, n);
            auto tail = current_head;
            merge(current_head, second_head, tail);
            current_head = next_head;
            tail->next = next_head;
        }
        n *= 2;
    }
}

int main() {
    auto head = list_generator({5, 4, 3, 2, 1});
    // auto head = list_generator({4, 3, 2, 1});
    head = sortList(head);
    print(head);
}