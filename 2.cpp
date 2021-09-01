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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto *res = new ListNode();
    auto digit = res;
    int carry = 0;
    auto a = l1, b = l2;
    while (a || b)
    {
        int temp = carry;
        if (a)
        {
            temp += a->val;
            a = a->next;
        }
        if (b)
        {
            temp += b->val;
            b = b->next;
        }
        carry = temp / 10;
        digit->val = temp % 10;
        if (a || b)
        {
            digit->next = new ListNode();
            digit = digit->next;
        }
    }
    if (carry)
        digit->next = new ListNode(carry);
    return res;
}