#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> bucket;
        deque<pair<int, int>> que;
        for (auto &i : nums) {
            ++bucket[i];
        }
        for (auto &i : bucket) {
            que.push_back({i.first, i.second});
        }
        partial_sort(que.begin(), que.begin() + k, que.end(), cmp);
        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; ++i) {
            ans.push_back(move(que[i].first));
        }
        return ans;
    }
};