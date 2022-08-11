#include "regular_headers.hpp"

vector<int> ans;

vector<vector<int>> res;

void recursive(int cur, int n, int k) {
    if (ans.size() == k) {
        res.push_back(ans);
        return;
    }
    if (cur > n) {
        return;
    }
    if (ans.size() + (n - cur + 1) < k) {
        return;
    }
    recursive(cur + 1, n, k);
    ans.push_back(cur);
    recursive(cur + 1, n, k);
    ans.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    recursive(1, n, k);
    return res;
}