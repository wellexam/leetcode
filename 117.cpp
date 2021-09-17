#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include "leetcode-binary-tree-generator.hpp"

using namespace std;

Node *connect(Node *root) {
    if (!root) {
        return root;
    }
    deque<Node *> que, que_sons;
    que.emplace_back(root);
    while (!que.empty()) {
        auto current = que.front();
        que.pop_front();
        if (!que.empty()) {
            current->next = que.front();
        } else {
            current->next = nullptr;
        }
        if (current->left) {
            que_sons.emplace_back(current->left);
        }
        if (current->right) {
            que_sons.emplace_back(current->right);
        }
        if (que.empty()) {
            swap(que, que_sons);
        }
    }
    return root;
}