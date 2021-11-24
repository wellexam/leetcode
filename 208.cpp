#include "regular_headers.hpp"

using namespace std;

class Trie {
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

    trie root;

public:
    Trie() {}

    void insert(string word) {
        if (word.empty()) {
            return;
        }
        auto current = &root;
        for (auto &i : word) {
            if (current->children[i - 'a']) {
                current = current->children[i - 'a'];
            } else {
                current->children[i - 'a'] = new trie;
                current = current->children[i - 'a'];
            }
        }
        current->is_end = true;
    }

    bool search(string word) {
        auto current = &root;
        for (auto &i : word) {
            if (current->children[i - 'a']) {
                current = current->children[i - 'a'];
            } else {
                return false;
            }
        }
        return current->is_end;
    }

    bool startsWith(string prefix) {
        auto current = &root;
        for (auto &i : prefix) {
            if (current->children[i - 'a']) {
                current = current->children[i - 'a'];
            } else {
                return false;
            }
        }
        return current != &root;
    }
};