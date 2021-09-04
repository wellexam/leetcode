#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {
    }
};

void search(TreeNode *root, TreeNode *parent, int key, bool left_or_right) {
    if (!root)
        return;
    if (root->val == key) {
        if (!root->left && !root->right) {
            if (left_or_right) {
                parent->left = nullptr;
                delete root;
                return;
            } else {
                parent->right = nullptr;
                delete root;
                return;
            }
        } else if (!root->right) {
            if (left_or_right) {
                parent->left = root->left;
                delete root;
                return;
            } else {
                parent->right = root->left;
                delete root;
                return;
            }
        } else if (!root->left) {
            if (left_or_right) {
                parent->left = root->right;
                delete root;
                return;
            } else {
                parent->right = root->right;
                delete root;
                return;
            }
        } else {
            auto cur = root->left;
            while (cur->right)
                cur = cur->right;
            cur->right = root->right;
            if (left_or_right) {
                parent->left = root->left;
                delete root;
                return;
            } else {
                parent->right = root->left;
                delete root;
                return;
            }
            delete root;
            return;
        }
    } else {
        if (root->left || root->right) {
            if (root->val < key) {
                search(root->right, root, key, false);
            } else {
                search(root->left, root, key, true);
            }
            return;
        } else
            return;
    }
}

TreeNode *deleteNode(TreeNode *root, int key) {
    auto dummy_node = new TreeNode(0, root, nullptr);
    search(root, dummy_node, key, true);
    auto ans = dummy_node->left;
    delete dummy_node;
    return ans;
}

int main() {
    auto *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    deleteNode(root, 5);
    delete root;
    return 0;
}