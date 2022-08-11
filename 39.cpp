#include "regular_headers.hpp"

vector<vector<int>> res;
vector<int> ans;

void recursive(vector<int> &candidates, int i, int sum, int target) {
    if (sum == target) {
        res.push_back(ans);
        return;
    }
    if (i == candidates.size())
        return;
    recursive(candidates, i + 1, sum, target);
    int j;
    for (j = 0; sum + candidates[i] <= target; j++) {
        sum += candidates[i];
        ans.emplace_back(candidates[i]);
        recursive(candidates, i + 1, sum, target);
    }
    if (j)
        ans.erase(ans.end() - j, ans.end());
    return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    recursive(candidates, 0, 0, target);
    return res;
}