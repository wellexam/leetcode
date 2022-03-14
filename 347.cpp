#include "regular_headers.hpp"

using namespace std;

bool ksort(vector<pair<int, int>> &nums, int left, int right, int k) {
    if (left >= right) {
        return false;
    }
    int pivot = left + rand() % (right - left + 1);
    int flag = nums[pivot].second;
    swap(nums[left], nums[pivot]);
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j].second >= flag) {
            j--;
        }
        while (i < j && nums[i].second <= flag) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    if (i == nums.size() - k) {
        return true;
    }
    if (i > nums.size() - k) {
        return ksort(nums, left, i, k);
    } else {
        return ksort(nums, i + 1, right, k);
    }
}

vector<int> topKFrequent(vector<int> &nums, int k) {
    srand(time(0));
    unordered_map<int, int> umap;
    for (auto &i : nums) {
        umap[i]++;
    }
    vector<pair<int, int>> Sort;
    Sort.reserve(umap.size());
    for (auto &i : umap) {
        Sort.emplace_back(i.first, i.second);
    }
    ksort(Sort, 0, Sort.size() - 1, k);
    vector<int> ans(k, 0);
    for (int i = 1; i <= k; i++) {
        ans[i - 1] = Sort[Sort.size() - i].first;
    }
    return ans;
}

int main() {
    vector<int> nums{1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 7, 7, 7, 8, 8, 9, 9, 0};
    auto ans = topKFrequent(nums, 3);
    return 0;
}