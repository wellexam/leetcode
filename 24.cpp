#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() :
        val(0), next(nullptr) {
    }

    ListNode(int x) :
        val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) :
        val(x), next(next) {
    }
};

ListNode *swapPairs(ListNode *head) {
    if (!head)
        return head;
    auto first = head, second = head->next;
    auto save = second;
    while (first && second) {
        auto temp = second->next;
        second->next = first;
        if (temp && temp->next) {
            first->next = temp->next;
            first = temp;
            second = temp->next;
        } else if (temp) {
            first->next = temp;
            first = first->next;
            second = nullptr;
        } else {
            first->next = nullptr;
            first = nullptr;
        }
    }
    if (save)
        return save;
    return head;
}

int main() {
    auto head = new ListNode(1);
    auto cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    head = swapPairs(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}