#include "regular_headers.hpp"

using namespace std;

void dfs(int pos, string &str, string &digits, unordered_map<char, vector<int>> &map, vector<string> &ans) {
    if (pos == digits.length()) {
        if (!str.empty()) {
            ans.emplace_back(str);
        }
        return;
    }
    int n = map[digits[pos]].size();
    while (n > 0) {
        --n;
        str.push_back(map[digits[pos]][n]);
        dfs(pos + 1, str, digits, map, ans);
        str.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<int>> map;
    map['2'] = {'a', 'b', 'c'};
    map['3'] = {'d', 'e', 'f'};
    map['4'] = {'g', 'h', 'i'};
    map['5'] = {'j', 'k', 'l'};
    map['6'] = {'m', 'n', 'o'};
    map['7'] = {'p', 'q', 'r', 's'};
    map['8'] = {'t', 'u', 'v'};
    map['9'] = {'w', 'x', 'y', 'z'};
    int n = digits.length();
    string str;
    vector<string> ans;
    dfs(0, str, digits, map, ans);
    return ans;
}