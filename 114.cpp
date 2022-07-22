#include "regular_headers.hpp"

void flatten(TreeNode *root) {
    if (!root)
        return;
    auto current_root = root;
    while (current_root) {
        auto rightest = current_root->left;
        while (rightest && rightest->right) {
            rightest = rightest->right;
        }
        if (!rightest) {
            current_root = current_root->right;
            continue;
        }
        rightest->right = current_root->right;
        current_root->right = current_root->left;
        current_root->left = nullptr;
        current_root = current_root->right;
    }
    return;
}

int main() {
    auto root = BTGenerator("1,2,5,3,4,null,6");
    flatten(root);
    return 0;
}