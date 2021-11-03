#pragma once
#include "list_node.hpp"
#include <initializer_list>

template <typename T>
ListNode * list_generator(std::initializer_list<T> ilist) {
    if (!ilist.size()) {
        return nullptr;
    }
    auto current = new ListNode();
    auto dummy = current;
    for (auto &i : ilist) {
        current->next = new ListNode(i);
        current = current->next;
    }
    auto head = dummy->next;
    delete dummy;
    return head;
}

void list_release(ListNode *head) {
    while (!head) {
        auto temp = head;
        head = head->next;
        delete temp;
    }
}