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

ListNode *deleteDuplicates(ListNode *head) {
    auto dummy_head = new ListNode(-101, head);
    auto forehead = new ListNode(-102, dummy_head);
    auto first = dummy_head, last = dummy_head, ahead = forehead;
    while (last->next) {
        if (last->next->val == last->val) {
            last = last->next;
        } else {
            if (last != first) {
                ahead->next = last->next;
                while (last != first) {
                    auto temp = first;
                    first = first->next;
                    delete temp;
                }
                delete last;
                last = ahead->next;
                first = last;
            } else {
                first = first->next;
                last = first;
                ahead = ahead->next;
            }
        }
    }
    if (last != first) {
        ahead->next = last->next;
        while (last != first) {
            auto temp = first;
            first = first->next;
            delete temp;
        }
        delete last;
        last = ahead->next;
        first = last;
    }
    auto temp = dummy_head->next;
    delete dummy_head;
    delete forehead;
    return temp;
}

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(1);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next->next = new ListNode(5);
    auto res = deleteDuplicates(head);
    return 0;
}