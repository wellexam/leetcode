#include "regular_headers.hpp"

using namespace std;

ListNode *sortList(ListNode *head) {
    ListNode *mid, *last;
    while (last->next) {
        last = last->next;
        if (last->next) {
            last = last->next;
        }
        if (mid->next) {
            mid = mid->next;
        }
    }
}

void sortlist(ListNode *start, ListNode *end) {
    if (start->next == end || start->next->next == end) {
        return;
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
    sortlist(start, mid);
    sortlist(mid, end);
}

void merge(ListNode *a, ListNode *b, ListNode *c, ListNode *d) {
    if (a !=b && c != d) {
        if (c->val < a->val) {
            auto cnext = c->next;
            c->next = a;
            a = c;
            c = cnext;
        }
    }
    while (a != b || c != d) {
        if (c->val >= a->val && a->next != b) {
            if (c->val <= a->next->val) {
                auto cnext = c->next, anext = a->next;
                a->next = c;
                c->next = anext;
                c = cnext;
                a = a->next;
            } else {
                a = a->next;
            }
        }
    }
    if (c != d) {
        auto anext = a->next;
        a->next = c;
        while (c->next != d) {
            c = c->next;
        }
        c->next = anext;
    }
}