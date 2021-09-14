#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int size = s.length(), sub = p.length();
    if (size < sub) {
        return {};
    }
    vector<int> table(26, 0);
    vector<int> target(26, 0);
    for (auto &i : p) {
        ++target[i - 'a'];
    }
    for (int i = 0; i < sub; ++i) {
        ++table[s[i] - 'a'];
    }
    vector<int> ans;
    int begin = 0;
    auto is_or_not = false;
    if (table == target) {
        is_or_not = true;
    }
    if (is_or_not) {
        ans.emplace_back(0);
    }
    for (int i = sub; i < size; ++i) {
        if (s[begin] == s[i]) {
            if (is_or_not) {
                ++begin;
                ans.emplace_back(begin);
                continue;
            } else {
                ++begin;
                continue;
            }
        } else {
            --table[s[begin] - 'a'];
            ++table[s[i] - 'a'];
            ++begin;
            if (is_or_not) {
                is_or_not = false;
                continue;
            } else if (table == target) {
                ans.emplace_back(begin);
                is_or_not = true;
            } else {
                continue;
            }
        }
    }
    return ans;
}