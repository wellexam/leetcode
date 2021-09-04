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

vector<int> rightSideView(TreeNode *root) {
    if (!root)
        return {};
    auto iter = root;
    deque<TreeNode *> que;
    vector<int> ans;
    que.push_front(root);
    while (!que.empty()) {
        int size = que.size();
        int last = que[size - 1]->val;
        ans.push_back(last);
        for (int i = 0; i < size; ++i) {
            if (que[0]->left)
                que.push_back(que[0]->left);
            if (que[0]->right)
                que.push_back(que[0]->right);
            que.pop_front();
        }
    }
    return ans;
}

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    auto ans = rightSideView(root);
    return 0;
}