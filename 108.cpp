#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recursive(int first, int last, TreeNode *node, bool left_or_right, vector<int> &nums)
{
    if (first == last)
    {
        if (left_or_right)
            node->left = new TreeNode(nums[first]);
        else
            node->right = new TreeNode(nums[first]);
        return;
    }
    int cur = (first + last) / 2;
    if (left_or_right)
    {
        node->left = new TreeNode(nums[cur]);
        recursive(first, cur - 1, node->left, true, nums);
        recursive(cur + 1, last, node->left, false, nums);
        return;
    }
    else
    {
        node->right = new TreeNode(nums[cur]);
        recursive(first, cur - 1, node->right, true, nums);
        recursive(cur + 1, last, node->right, false, nums);
        return;
    }
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int len = nums.size();
    int begin = 0, end = len - 1;
    int cur = (begin + end) / 2;
    auto *root = new TreeNode(nums[cur]);
    recursive(begin, cur - 1, root, true, nums);
    recursive(cur + 1, end, root, false, nums);
    return root;
}

int main()
{
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