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

void inorder(TreeNode *root, int k, int &count, int &ans) {
    if (!root)
        return;
    if (!root->left)
        ++count;
    if (count == k) {
        ans = root->val;
        return;
    }
    if (root->left) {
        inorder(root->left, k, count, ans);
        if (ans != -1) {
            return;
        } else {
            ++count;
            if (count == k) {
                ans = root->val;
                return;
            }
        }
    }
    inorder(root->right, k, count, ans);
    return;
}

int kthSmallest(TreeNode *root, int k) {
    int ans = -1, count = 0;
    inorder(root, k, count, ans);
    return ans;
}