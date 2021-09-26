#include "regular_headers.hpp"

using namespace std;

class trie {
public:
    vector<trie *> chileren{26, nullptr};
    bool is_end = false;
};

bool dfs(string &s, int pos, trie *root, trie *current) {
    
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
}