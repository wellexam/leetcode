#include "regular_headers.hpp"

using namespace std;

bool mid_order(TreeNode *root, deque<int> &que, int k) {
    if (root == nullptr) {
        return false;
    }
    if (mid_order(root->right, que, k)) {
        return true;
    }
    que.push_back(root->val);
    if (que.size() == k) {
        return true;
    }
    return mid_order(root->left, que, k);
}

int kthLargest(TreeNode *root, int k) {
    deque<int> que;
    mid_order(root, que, k);
    return que.back();
}

int main() {
    auto root = BTGenerator("2,1");
    cout << kthLargest(root, 2);
    return 0;
}