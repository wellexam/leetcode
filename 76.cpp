#include "regular_headers.hpp"

using namespace std;

bool check(unordered_map<char, int> &t_map) {
    for (auto &i : t_map) {
        if (i.second > 0) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    int begin = 0, end = 0;
    bool flag = false;
    pair<int, int> ans{0, s.size() - 1};
    unordered_map<char, int> t_map;
    for (auto i : t) {
        ++t_map[i];
    }
    if (t_map.find(s[end]) != t_map.end()) {
        --t_map[s[end]];
    }
    while (end <= s.size()) {
        auto b_res = t_map.find(s[begin]);
        while (begin <= end && (b_res == t_map.end() || t_map[s[begin]] < 0)) {
            if (b_res != t_map.end()) {
                ++t_map[s[begin]];
            }
            ++begin;
            b_res = t_map.find(s[begin]);
        }
        if (check(t_map)) {
            flag = true;
            if (ans.second - ans.first + 1 > end - begin + 1) {
                ans = {begin, end};
            }
        }
        ++end;
        if (end >= s.size()) {
            continue;
        }
        auto res = t_map.find(s[end]);
        if (res != t_map.end()) {
            --t_map[s[end]];
        }
    }
    if (!flag) {
        return "";
    }
    string res_str;
    res_str.reserve(ans.second - ans.first + 1);
    for (int i = ans.first; i <= ans.second; ++i) {
        res_str.push_back(s[i]);
    }
    return res_str;
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
}