#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool ksort(vector<pair<int, int>> &nums, int left, int right, int k) {
    if (left == right) {
        return false;
    }
    int flag = nums[left + (right - left) / 2].second;
    int i = left, j = right - 1;
    while (i < j) {
        while (i < j && nums[j].second >= flag) {
            j--;
        }
        while (i < j && nums[i].second < flag) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    if (i == nums.size() - k) {
        return true;
    }
    if (i < nums.size() - k) {
        return ksort(nums, i, right, k);
    } else {
        return ksort(nums, left, i, k);
    }
}

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    for (auto &i : nums) {
        umap[i]++;
    }
    vector<pair<int, int>> Sort;
    Sort.reserve(umap.size());
    for (auto &i : umap) {
        Sort.emplace_back(i.first, i.second);
    }
    ksort(Sort, 0, Sort.size(), k);
    vector<int> ans(k, 0);
    for (int i = 1; i <= k; i++) {
        ans[i - 1] = Sort[Sort.size() - i].first;
    }
    return ans;
}

int main() {
    vector<int> nums{1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 7, 7, 7, 8, 8, 9, 9, 0};
    topKFrequent(nums, 3);
    return 0;
}