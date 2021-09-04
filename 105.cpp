#include <algorithm>
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

void recursive(vector<int>::const_iterator pre_begin, vector<int>::const_iterator vin_begin, int len, TreeNode *node, bool left_or_right) {
    if (len == 0)
        return;
    if (len == 1) {
        if (left_or_right) {
            node->left = new TreeNode(*pre_begin);
            return;
        } else {
            node->right = new TreeNode(*pre_begin);
            return;
        }
    }
    int root = *pre_begin;
    int count = 0;
    while (*(vin_begin + count) != root)
        ++count;
    if (left_or_right) {
        node->left = new TreeNode(root);
        recursive(pre_begin + 1, vin_begin, count, node->left, true);
        recursive(pre_begin + 1 + count, vin_begin + 1 + count, len - 1 - count, node->left, false);
        return;
    } else {
        node->right = new TreeNode(root);
        recursive(pre_begin + 1, vin_begin, count, node->right, true);
        recursive(pre_begin + 1 + count, vin_begin + 1 + count, len - 1 - count, node->right, false);
        return;
    }
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int root_val = preorder[0];
    auto *root = new TreeNode(root_val);
    int len = 0;
    while (inorder[len] != root_val)
        ++len;
    recursive(preorder.begin() + 1, inorder.begin(), len, root, true);
    recursive(preorder.begin() + 1 + len, inorder.begin() + 1 + len, preorder.size() - 1 - len, root, false);
    return root;
}

//妈的，一遍编译加过题，爽！！！