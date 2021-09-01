#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class MyLinkedList
{

private:

	class ListNode
	{
	public:
		int val;
		ListNode *next;
		ListNode *prev;

		ListNode() : val(0), next(nullptr), prev(nullptr) {}

		explicit ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}

		ListNode(int x, ListNode *prev) : val(x), prev(prev), next(nullptr) {}

		ListNode(int x, ListNode *prev, ListNode *next) : val(x), prev(prev), next(next) {}
	};

	int len;
	ListNode *head;
public:
	/** Initialize your data structure here. */
	MyLinkedList()
	{
		len = 0;
		head = new ListNode(0);
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index > len - 1)
			return -1;
		auto cur = head;
		for (int i = 0; i < index; ++i)
			cur = cur->next;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		if (len == 0)
		{
			head->val = val;
			++len;
			return;
		}
		head->prev = new ListNode(val, nullptr, head);
		head = head->prev;
		++len;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		if (len == 0)
		{
			head->val = val;
			++len;
			return;
		}
		auto cur = head;
		while (cur->next)
			cur = cur->next;
		cur->next = new ListNode(val, cur, nullptr);
		++len;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index > len)
			return;
		if (index <= 0)
		{
			addAtHead(val);
			return;
		}
		if (index == len)
		{
			addAtTail(val);
			return;
		}
		auto cur = head;
		for (int i = 0; i < index; ++i)
			cur = cur->next;
		auto front = cur->prev;
		auto *new_node = new ListNode(val, front, cur);
		front->next = new_node;
		cur->prev = new_node;
		++len;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index < 0 || index > len - 1)
			return;
		if (len == 0)
			return;
		if (index == 0)
		{
			auto new_head = head->next;
			if (new_head)
				new_head->prev = nullptr;
			delete head;
			head = new_head;
			--len;
			return;
		}
		auto cur = head;
		for (int i = 0; i < index; ++i)
			cur = cur->next;
		auto front = cur->prev;
		front->next = cur->next;
		if (cur->next)
			cur->next->prev = front;
		delete cur;
		--len;
	}
};