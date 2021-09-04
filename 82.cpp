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
    if (!head)
        return head;
    auto *forehead = new ListNode(-101, head), *foreheads = new ListNode(-102, forehead);
    auto cur = forehead, last = foreheads, next = cur->next;
    int del_val = foreheads->val;
    bool flag = false;
    while (next) {
        if (cur->val == next->val && next->val == del_val) {
            cur = next;
            next = next->next;
            flag = true;
        } else if (cur->val == next->val) {
            del_val = cur->val;
            cur = next;
            next = next->next;
            flag = true;
        } else if (flag) {
            last->next = next;
            flag = false;
            cur = next;
            next = next->next;
        } else {
            last = cur;
            cur = next;
            next = next->next;
        }
    }
    if (cur && del_val == cur->val)
        last->next = nullptr;
    head = forehead->next;
    return head;
}

int main() {
    int input;
    char ch;
    auto *head = new ListNode();
    auto cur = head;
    string s;
    cin >> s;
    head->val = s[0] - '0';
    for (int i = 1; i < s.length(); ++i)
        if (s[i] >= '0' && s[i] <= '9') {
            cur->next = new ListNode(s[i] - '0');
            cur = cur->next;
        }
    head = deleteDuplicates(head);
    cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}