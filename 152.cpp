#include "regular_headers.hpp"

int maxProduct(vector<int> &nums) {
    int ans = nums.front();
    vector<pair<int, int>> vec;
    vec.reserve(nums.size());
    vec.emplace_back(nums.front(), nums.front());
    for (int i = 1, size = nums.size(); i < size; ++i) {
        int a = nums[i] * vec[i - 1].first;
        int b = nums[i] * vec[i - 1].second;
        vec.emplace_back(max(a, max(b, nums[i])), min(a, min(b, nums[i])));
        ans = max(max(vec[i].first, vec[i].second), ans);
    }
    return ans;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, -6, 7, 8, -9, 4};
    cout << maxProduct(nums);
}