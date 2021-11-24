#include "regular_headers.hpp"

using namespace std;

class trie {
public:
    vector<trie *> children{26, nullptr};
    bool is_end = false;

    ~trie() {
        for (auto &i : children) {
            delete i;
        }
    }
};

bool dfs(string &s, int pos, trie *root, unordered_map<int, vector<pair<int, trie *>>> &map) {
    if (pos == s.size()) {
        return true;
    }
    int current = pos;
    auto current_node = root;
    if (map.find(pos) != map.end()) {
        for (auto &i : map[pos]) {
            if (dfs(s, i.first + 1, root, map)) {
                return true;
            }
        }
        current = (map[pos].end() - 1)->first + 1;
        current_node = (map[pos].end() - 1)->second;
    }
    while (current < s.size() && current_node->children[s[current] - 'a']) {
        current_node = current_node->children[s[current] - 'a'];
        if (current_node->is_end) {
            map[pos].emplace_back(current, current_node);
            if (dfs(s, current + 1, root, map)) {
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
            if (current->children[j - 'a']) {
                current = current->children[j - 'a'];
            } else {
                current->children[j - 'a'] = new trie;
                current = current->children[j - 'a'];
            }
        }
        current->is_end = true;
    }
    unordered_map<int, vector<pair<int, trie *>>> map;
    return dfs(s, 0, &root, map);
}

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    cout << wordBreak(s, wordDict);
    return 0;
}