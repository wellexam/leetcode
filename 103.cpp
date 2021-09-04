#include <algorithm>
#include <deque>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};
    bool direction = true;
    deque<TreeNode *> que_1, que_2;
    vector<vector<int>> ans;
    que_1.push_back(root);
    while (!que_1.empty() || !que_2.empty())
    {
        if (direction)
        {
            auto iter = que_1.cbegin();
            auto end = que_1.cend();
            vector<int> temp;
            while (iter != end)
            {
                temp.push_back((*iter)->val);
                if ((*iter)->left)
                {
                    que_2.push_front((*iter)->left);
                }
                if ((*iter)->right)
                {
                    que_2.push_front((*iter)->right);
                }
                ++iter;
            }
            ans.push_back(temp);
            direction = !direction;
            que_1.clear();
        }
        else
        {
            auto iter = que_2.cbegin();
            auto end = que_2.cend();
            vector<int> temp;
            while (iter != que_2.cend())
            {
                temp.push_back((*iter)->val);
                if ((*iter)->right)
                {
                    que_1.push_front((*iter)->right);
                }
                if ((*iter)->left)
                {
                    que_1.push_front((*iter)->left);
                }
                ++iter;
            }
            ans.push_back(temp);
            direction = !direction;
            que_2.clear();
        }
    }
    return ans;
}

int main()
{
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    zigzagLevelOrder(root);
    delete root;
    return 0;
}