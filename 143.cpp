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

void reorderList(ListNode *head) {
    vector<ListNode *> list;
    list.reserve(50000);
    auto iter = head;
    while (iter) {
        list.push_back(iter);
        iter = iter->next;
    }
    int len = list.size();
    int back = len - 1;
    int i = 0;
    for (; i < back - i; ++i) {
        list[i]->next = list[back - i];
        list[back - i]->next = list[i + 1];
    }
    list[i]->next = nullptr;
}

int main() {
    auto *head = new ListNode(0);
    auto heads = head;
    head->next = new ListNode(1);
    head = head->next;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    head = head->next;
    head->next = new ListNode(5);
    head = head->next;
    head->next = new ListNode(6);
    head = head->next;
    //head->next = new ListNode(7);
    //head = head->next;
    reorderList(heads);
    return 0;
}