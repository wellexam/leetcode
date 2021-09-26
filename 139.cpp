#include "regular_headers.hpp"

using namespace std;

class trie {
public:
    vector<trie *> chileren{26, nullptr};
    bool is_end = false;
};

bool dfs(string &s, int pos, trie *root) {
    if (pos == s.size()) {
        return true;
    }
    int current = pos;
    auto current_node = root;
    while (current < s.size() && current_node->chileren[s[current] - 'a']) {
        current_node = current_node->chileren[s[current] - 'a'];
        if (current_node->is_end) {
            if (dfs(s, current + 1, root)) {
                return true;
            }
        }
        ++current;
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict) {
    trie root;
    for (auto &i : wordDict) {
        auto current = &root;
        for (auto &j : i) {
            if (current->chileren[j - 'a']) {
                current = current->chileren[j - 'a'];
            } else {
                current->chileren[j - 'a'] = new trie;
                current = current->chileren[j - 'a'];
            }
        }
        current->is_end = true;
    }
    return dfs(s, 0, &root);
}

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    cout << wordBreak(s, wordDict);
    return 0;
}