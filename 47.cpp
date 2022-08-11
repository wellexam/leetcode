#include "regular_headers.hpp"

vector<int> ans;
vector<vector<int>> res;

void recursive(map<int, int> &nums, int i) {
    if (i == ans.size()) {
        res.push_back(ans);
    }
    for (auto &p : nums) {
        if (p.second) {
            ans[i] = p.first;
            p.second--;
            recursive(nums, i + 1);
            p.second++;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    map<int, int> Map;
    ans = vector<int>(nums.size());
    for (auto i : nums) {
        Map[i]++;
    }
    recursive(Map, 0);
    return res;
}