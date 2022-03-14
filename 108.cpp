#include "regular_headers.hpp"

using namespace std;

bool recursive(vector<int> &nums, TreeNode *root, int left, int right) {
    if (left == right) {
        return false;
    }
    int mid = left + (right - left) / 2;
    root->val = nums[mid];
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    if (!recursive(nums, root->left, left, mid)) {
        delete root->left;
        root->left = nullptr;
    }
    if (!recursive(nums, root->right, mid + 1, right)) {
        delete root->right;
        root->right = nullptr;
    }
    return true;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    int left = 0, right = nums.size(), mid = left + (right - left) / 2;
    auto root = new TreeNode(nums[mid]);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    if (!recursive(nums, root->left, left, mid)) {
        delete root->left;
        root->left = nullptr;
    }
    if (!recursive(nums, root->right, mid + 1, right)) {
        delete root->right;
        root->right = nullptr;
    }
    return root;
}

int main() {
    // int a = 1, sum  = 1;
    // for (int i = 1; i < 13; ++i)
    // {
    //     a = a * 2;
    //     sum += a;
    // }
    // cout << sum;
    vector<int> nums = {-10, -3, 0, 5, 9};
    auto root = sortedArrayToBST(nums);
    return 0;
}