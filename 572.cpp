#include "regular_headers.hpp"

using namespace std;

bool dfs(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot) {
        return true;
    } else if (!root || !subRoot) {
        return false;
    }
    if (root->val == subRoot->val) {
        return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
    }
    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root) {
        if (!subRoot) {
            return true;
        } else {
            return false;
        }
    }
    deque<TreeNode *> que;
    que.emplace_back(root);
    while (!que.empty()) {
        auto current = que.front();
        que.pop_front();
        if (current->left) {
            que.emplace_back(current->left);
        }
        if (current->right) {
            que.emplace_back(current->right);
        }
        if (current->val == subRoot->val && dfs(current, subRoot)) {
            return true;
        }
    }
    return false;
}