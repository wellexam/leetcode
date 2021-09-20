#include "regular_headers.hpp"

using namespace std;

void dfs(int sum, int index, int target, vector<pair<int, int>> &shit, vector<int> &set, vector<vector<int>> &ans) {
    if (index == shit.size()) {
        return;
    }
    dfs(sum, index + 1, target, shit, set, ans);
    auto count = 0;
    auto current = shit[index].first;
    while (count < shit[index].second) {
        ++count;
        set.emplace_back(current);
        sum += current;
        if (sum == target) {
            ans.emplace_back(set);
            break;
        } else if (sum > target) {
            break;
        } else {
            dfs(sum, index + 1, target, shit, set, ans);
        }
    }
    while (count > 0) {
        set.pop_back();
        --count;
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> set;
    vector<vector<int>> ans;
    unordered_map<int, int> map;
    for (auto &i : candidates) {
        ++map[i];
    }
    vector<pair<int, int>> shit;
    for (auto &i : map) {
        shit.emplace_back(i.first, i.second);
    }
    dfs(0, 0, target, shit, set, ans);
    return ans;
}