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

ListNode *detectCycle(ListNode *head) {
    if (!head)
        return nullptr;
    auto slow = head, fast = head;
    int distance = 0;
    do {
        if (!(slow = slow->next))
            return nullptr;
        if (!(fast = fast->next))
            return nullptr;
        if (!(fast = fast->next))
            return nullptr;
        ++distance;
    } while (fast != slow);
    auto begin = head, end = head;
    for (int i = 0; i < distance; ++i)
        end = end->next;
    while (end != begin) {
        begin = begin->next;
        end = end->next;
    }
    return begin;
}