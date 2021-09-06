#include <deque>
#include <sstream>
#include <string>
#include <iostream>

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

class Codec {
public:
    void replaceAll(std::string &source, const std::string &from, const std::string &to) {
        std::string newString;
        newString.reserve(source.length()); // avoids a few memory allocations

        std::string::size_type lastPos = 0;
        std::string::size_type findPos;

        while (std::string::npos != (findPos = source.find(from, lastPos))) {
            newString.append(source, lastPos, findPos - lastPos);
            newString += to;
            lastPos = findPos + from.length();
        }

        // Care for the rest after last occurrence
        newString += source.substr(lastPos);

        source.swap(newString);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) {
            return "";
        }
        deque<TreeNode *> nodes;
        string vals;
        nodes.push_back(root);
        auto current = root;
        while (!nodes.empty()) {
            current = nodes.front();
            nodes.pop_front();
            if (current) {
                nodes.push_back(current->left);
                nodes.push_back(current->right);
                vals += to_string(current->val);
                vals += ",";
            } else {
                vals += "null,";
            }
        }
        vals.pop_back();
        auto temp = string(vals.end() - 4, vals.end());
        while (temp == "null") {
            vals.erase(vals.end() - 5, vals.end());
            if (vals.length() > 4) {
                temp = string(vals.end() - 4, vals.end());
            } else {
                temp = "";
            }
        }
        return vals;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string str) {
        if (str == "") {
            return nullptr;
        }
        replaceAll(str, ",", " ");
        replaceAll(str, "null", "-2147483648");
        stringstream stream;
        stream << str;
        deque<TreeNode *> que, parents;
        deque<int> node_vals;
        auto count = 0, product = 2;
        auto node_val = 0;
        while (stream >> node_val) {
            node_vals.push_back(node_val);
        }
        auto root = new TreeNode(node_vals[0]);
        parents.push_back(root);
        node_vals.pop_front();
        while (!node_vals.empty()) {
            for (; count < product && !node_vals.empty(); ++count) {
                if (node_vals[0] != 1 << 31) {
                    auto temp = new TreeNode(node_vals[0]);
                    if (count % 2) {
                        parents[count / 2]->right = temp;
                    } else {
                        parents[count / 2]->left = temp;
                    }
                    que.push_back(temp);
                }
                node_vals.pop_front();
            }
            parents.clear();
            swap(parents, que);
            product = parents.size() * 2;
            count = 0;
        }
        return root;
    }
};

int main() {
    Codec a;
    auto root = a.deserialize("1,2");
    auto ans = a.serialize(root);
    root = a.deserialize(ans);
    ans = a.serialize(root);
    cout << ans;
    return 0;
}