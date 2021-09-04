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

void dfs(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &paths) {
    if (!root) {
        return;
    }
    targetSum -= root->val;
    if (targetSum != 0) {
        path.push_back(root->val);
        dfs(root->left, targetSum, path, paths);
        dfs(root->right, targetSum, path, paths);
        path.pop_back();
        return;
    } else {
        if (!root->left && !root->right) {
            path.push_back(root->val);
            paths.push_back(path);
            path.pop_back();
        } else {
            path.push_back(root->val);
            dfs(root->left, targetSum, path, paths);
            dfs(root->right, targetSum, path, paths);
            path.pop_back();
        }
        return;
    }
    return;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> paths;
    vector<int> path;
    dfs(root, targetSum, path, paths);
    return paths;
}