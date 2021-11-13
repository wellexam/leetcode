#include "regular_headers.hpp"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *last = head, *ans = head, *before_ans = head;
    auto dummy = new ListNode;
    dummy->next = head;
    before_ans = dummy;
    for (int i = 1; i < n; ++i) {
        last = last->next;
    }
    while (last->next) {
        last = last->next;
        ans = ans->next;
        before_ans = before_ans->next;
    }
    before_ans->next = ans->next;
    delete ans;
    ans = dummy->next;
    delete dummy;
    return ans;
}