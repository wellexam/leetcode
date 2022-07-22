#include "regular_headers.hpp"

int ans;

int maxGain(TreeNode *root) {
    if (!root)
        return 0;
    int leftValue = maxGain(root->left), rightValue = maxGain(root->right);
    auto temp = max(leftValue, max(rightValue, 0)) + root->val;
    ans = max(ans,  max(leftValue, 0) + max(rightValue, 0) + root->val);
    return temp;
}

int maxPathSum(TreeNode *root) {
    ans = root->val;
    auto temp = max(maxGain(root->left), 0) + max(maxGain(root->right), 0) + root->val;
    ans = max(ans, temp);
    return ans;
}