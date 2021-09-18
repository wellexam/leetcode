#include "regular_headers.hpp"

using namespace std;

typedef unordered_map<int, int>::const_iterator iter;

void dfs(iter current, iter end, vector<int> &set, vector<vector<int>> &ans) {
    if (current == end) {
        ans.emplace_back(set);
        return;
    }
    auto temp = current;
    ++temp;
    dfs(temp, end, set, ans);
    int num = current->first;
    int count = current->second;
    for (int i = 0; i < count; ++i) {
        set.emplace_back(num);
        dfs(temp, end, set, ans);
    }
    for (int i = 0; i < count; ++i) {
        set.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> map;
    for (auto &i : nums) {
        ++map[i];
    }
    auto begin = map.cbegin();
    auto end = map.cend();
    vector<int> set;
    vector<vector<int>> ans;
    dfs(begin, end, set, ans);
    return ans;
}