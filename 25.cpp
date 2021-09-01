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

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k == 1)
		return head;
    auto *dummy_node = new ListNode(0, head);
    auto iter = head, temp = head->next, last = dummy_node;
    while (iter)
    {
        int count = 0;
        temp = iter;
        auto shit = iter;
        while (temp && count < k - 1)
        {
            temp = temp->next;
            ++count;
        }
        if (count < k - 1 || !temp)
            break;
        last->next = temp;
        temp = temp->next;
        for (int i = 0; i < k; ++i)
        {
            auto temp_s = iter->next;
            iter->next = temp;
            temp = iter;
            iter = temp_s;
        }
        last = shit;
    }
    return dummy_node->next;
}