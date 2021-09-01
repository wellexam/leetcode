#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a = headA, b = headB;
    bool is_a = false, is_b = false;
    while (a && b)
    {
        if ((a == b) && a)
            return a;
        if (!a->next && !is_a)
        {
            a = headB;
            is_a = true;
        }
        else if (a->next)
            a = a->next;
        else if (!a->next)
            return nullptr;
        if (!b->next && !is_b)
        {
            b = headA;
            is_b = true;
        }
        else if (b->next)
            b = b->next;
        else if (!b->next)
            return nullptr;
    }
    return nullptr;
}