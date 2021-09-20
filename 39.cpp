#include "regular_headers.hpp"

using namespace std;

void dfs(int sum, int index, int target, vector<int> &candidates, vector<int> &set, vector<vector<int>> &ans) {
    if (index == candidates.size()) {
        return;
    }
    auto current = candidates[index];
    if (sum == target) {
        ans.emplace_back(set);
        return;
    }
    dfs(sum, index + 1, target, candidates, set, ans);
    auto count = 0;
    while (sum <= target) {
        sum += current;
        if (sum > target) {
            break;
        } else if (sum == target) {
            set.emplace_back(current);
            ++count;
            ans.emplace_back(set);
            break;
        } else {
            set.emplace_back(current);
            ++count;
            dfs(sum, index + 1, target, candidates, set, ans);
        }
    }
    while (count > 0) {
        set.pop_back();
        --count;
    }
    return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> set;
    vector<vector<int>> ans;
    dfs(0, 0, target, candidates, set, ans);
    return ans;
}