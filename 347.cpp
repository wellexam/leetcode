#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> bucket;
        vector<pair<int, int>> heap;
        for (auto &i : nums) {
            ++bucket[i];
        }
        auto size = bucket.size();
        auto iter = bucket.begin();
        int i = 0;
        while (i < k - 1) {
            heap.emplace_back(iter->first, iter->second);
            ++iter;
            ++i;
        }
        if (i == k - 1) {
            heap.emplace_back(iter->first, iter->second);
            for (int j = k - 1; j > 0; --j) {
                int father = (j - 1) / 2;
                if (heap[father].second > heap[j].second) {
                    swap(heap[father], heap[j]);
                }
            }
            ++iter;
            ++i;
        }
        while (i < size) {
            if (iter->second > heap[0].second) {
                heap[0] = {iter->first, iter->second};
                for (int j = k - 1; j > 0; --j) {
                    int father = (j - 1) / 2;
                    if (heap[father].second > heap[j].second) {
                        swap(heap[father], heap[j]);
                    }
                }
            }
            ++iter;
            ++i;
        }
        vector<int> ans(k);
        for (i = 0; i < k; ++i) {
            ans[i] = heap[i].first;
        }
        return ans;
    }
};