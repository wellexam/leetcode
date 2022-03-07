#include "regular_headers.hpp"


ListNode *reverseList(ListNode *head) {
    auto current = head;
    auto last = new ListNode;
    auto to_delete = last;
    while (current->next) {
        auto n_ptr = current->next;
        current->next = last;
        last = current;
        current = n_ptr;
    }
    current->next = last;
    delete to_delete;
    head->next = nullptr;
    return current;
}

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto h = reverseList(head);
    return 0;
}