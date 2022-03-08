#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> umap;
    unordered_map<string, char> r_umap;
    int cursor = 0;
    for (int i = 0; i < pattern.size(); i++) {
        string temp;
        while (cursor < s.size() && s[cursor] != ' ') {
            temp.push_back(s[cursor]);
            cursor++;
        }
        cursor++;
        auto iter = umap.find(pattern[i]);
        auto iter2 = r_umap.find(temp);
        if (iter == umap.end()) {
            umap[pattern[i]] = temp;
            if (iter2 != r_umap.end()) {
                return false;
            } else {
                r_umap[temp] = pattern[i];
            }
            continue;
        } else {
            if (iter->second == temp) {
                continue;
            } else {
                return false;
            }
        }
    }
    if (cursor <= s.size()) {
        return false;
    }
    return true;
}

int main() {
    cout << wordPattern("he", "unit");
    return 0;
}