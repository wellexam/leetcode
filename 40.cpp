#include "regular_headers.hpp"

vector<vector<int>> res;
vector<int> ans;

void recursive(map<int, int> &candidates, int target, int sum, map<int, int>::iterator iter) {
    if (sum == target) {
        res.push_back(ans);
        return;
    }
    if (iter == candidates.end()) {
        return;
    }
    recursive(candidates, target, sum, ++iter);
    --iter;
    int j;
    for (j = 0; iter->second && iter->first + sum <= target; j++) {
        sum += iter->first;
        iter->second--;
        ans.emplace_back(iter->first);
        recursive(candidates, target, sum, ++iter);
        --iter;
    }
    iter->second += j;
    ans.erase(ans.end() - j, ans.end());
    return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    map<int, int> Map;
    for (auto i : candidates) {
        Map[i]++;
    }
    recursive(Map, target, 0, Map.begin());
    return res;
}