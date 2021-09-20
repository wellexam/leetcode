#include "regular_headers.hpp"

using namespace std;

void dfs(int current, vector<int> &set, vector<pair<int, int>> &digits, vector<vector<int>> &ans) {
    set.emplace_back(digits[current].first);
    --digits[current].second;
    auto is_end = true;
    for (int i = 0; i < digits.size(); ++i) {
        if (digits[i].second) {
            dfs(i, set, digits, ans);
            is_end = false;
        }
    }
    ++digits[current].second;
    if (is_end) {
        ans.emplace_back(set);
    }
    set.pop_back();
    return;
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    unordered_map<int, int> map;
    for (auto &i : nums) {
        ++map[i];
    }
    int n = map.size();
    vector<pair<int, int>> digits;
    for (auto &i : map) {
        digits.emplace_back(i.first, i.second);
    }
    vector<int> set;
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        dfs(i, set, digits, ans);
    }
        return ans;
}