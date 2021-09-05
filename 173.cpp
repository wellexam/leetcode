#include "leetcode-binary-tree-generator.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class BSTIterator {
private:
    stack<TreeNode *> stack;
    TreeNode *current;

    void reverse_preorder(TreeNode *node);

public:
    BSTIterator(TreeNode *root) {
        current = root;
        while (current->left) {
            stack.push(current);
            current = current->left;
        }
        stack.push(current);
    }

    int next() {
        current = stack.top();
        stack.pop();
        if (current->right) {
            auto temp = current->right;
            while (temp) {
                stack.push(temp);
                temp = temp->left;
            }
        }
        return current->val;
    }

    bool hasNext() {
        return !stack.empty() || current->right;
    }
};

void BSTIterator::reverse_preorder(TreeNode *node) {
    if (!node)
        return;
    reverse_preorder(node->right);
    stack.push(node);
    reverse_preorder(node->left);
    return;
}

int main() {
    auto root = BTGenerator("41,37,44,24,39,42,48,1,35,38,40,null,43,46,49,0,2,30,36,null,null,null,null,null,null,45,47,null,null,null,null,null,4,29,32,null,null,null,null,null,null,3,9,26,null,31,34,null,null,7,11,25,27,null,null,33,null,6,8,10,16,null,null,null,28,null,null,5,null,null,null,null,null,15,19,null,null,null,null,12,null,18,20,null,13,17,null,null,22,null,14,null,null,21,23");
    auto iter = BSTIterator(root);
    while (iter.hasNext()) {
        cout << iter.next() << endl;
    }
    return 0;
}