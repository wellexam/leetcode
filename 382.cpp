#include "regular_headers.hpp"

class Solution {
public:
    ListNode *_head;
    random_device rd;
    minstd_rand engine;

    Solution(ListNode *head) : _head(head), rd(), engine(rd()) {}

    int getRandom() {
        auto p = _head;
        int res = 0;
        int i = 0;
        while (p) {
            i++;
            if (!((engine() - 1) % i)) {
                res = p->val;
            }
            p = p->next;
        }
        return res;
    }
};