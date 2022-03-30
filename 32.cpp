#include "regular_headers.hpp"

using namespace std;

int longestValidParentheses(string s) {
    int ans = 0;
    stack<pair<char, int>> stk;
    vector<pair<int, int>> range, merge;
    for (int i = 0; i < s.size(); i++) {
        if (!stk.empty()) {
            if (stk.top().first == '(' && s[i] == ')') {
                range.push_back({stk.top().second, i});
                stk.pop();
            } else {
                stk.push({s[i], i});
            }
        } else {
            stk.push({s[i], i});
        }
    }
    sort(range.begin(), range.end());
    if (range.empty()) {
        return 0;
    }
    merge.push_back(range[0]);
    for (int i = 1; i < range.size(); i++) {
        if (range[i].first < merge.back().second) {
            continue;
        } else if (range[i].first == merge.back().second + 1) {
            merge.back().second = range[i].second;
            continue;
        } else {
            merge.push_back(range[i]);
        }
    }
    for (auto &i : merge) {
        ans = max(ans, i.second - i.first + 1);
    }
    return ans;
}

int main() {
    string s = ")()())";
    cout << longestValidParentheses(s);
    return 0;
}