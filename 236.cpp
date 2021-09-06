#include "leetcode-binary-tree-generator.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool preorder_search(TreeNode *root, TreeNode *target1, TreeNode *target2, deque<TreeNode *> &path) {
    if (!root)
        return false;
    if (root != target1 && root != target2) {
        path.push_front(root);
        if (preorder_search(root->left, target1, target2, path)) {
            return true;
        }
        if (preorder_search(root->right, target1, target2, path)) {
            return true;
        }
        path.pop_front();
        return false;
    } else {
        path.push_front(root);
        return true;
    }
}

bool preorder_search(TreeNode *root, TreeNode *target) {
    if (!root) {
        return false;
    }
    if (root == target) {
        return true;
    }
    if (preorder_search(root->left, target)) {
        return true;
    }
    if (preorder_search(root->right, target)) {
        return true;
    }
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    deque<TreeNode *> path;
    preorder_search(root, p, q, path);
    if (q == path[0]) {
        swap(p, q);
    }
    auto last = path[0];
    auto current = last;
    auto ans = current;
    ans = nullptr;
    auto if_find = false;
    path.pop_front();
    while (!path.empty()) {
        current = path.front();
        path.pop_front();
        if (current->right != last) {
            if (preorder_search(current->right, q)) {
                ans = current;
                if_find = true;
            }
        }
        last = current;
        if (if_find) {
            break;
        }
    }
    if (!ans) {
        ans = p;
    }
    return ans;
}

TreeNode *preorder_search(TreeNode *root, int val) {
    if (!root) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }
    auto ans = preorder_search(root->left, val);
    if (ans) {
        return ans;
    }
    ans = preorder_search(root->right, val);
    return ans;
}