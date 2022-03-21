#include "regular_headers.hpp"

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.empty()) {
        return {};
    }
    sort(nums.begin(), nums.end());
    int last_i = 100001;
    vector<vector<int>> ans;
    for (int i = 0; i + 2 < nums.size(); i++) {
        if (nums[i] == last_i) {
            continue;
        }
        last_i = nums[i];
        int last_j = 100001;
        for (int j = static_cast<int>(nums.size()) - 1; j >= i + 2; j--) {
            if (nums[j] == last_j) {
                continue;
            }
            last_j = nums[j];
            int target = 0 - nums[i] - nums[j];
            if (target > nums[j]) {
                break;
            }
            if (target < nums[i]) {
                continue;
            }
            int left = i + 1, right = j, mid = left + (right - left) / 2;
            while (left < right) {
                if (nums[mid] == target) {
                    ans.emplace_back(vector<int>{nums[i], nums[mid], nums[j]});
                    break;
                }
                if (nums[mid] < target) {
                    left = mid + 1;
                    mid = left + (right - left) / 2;
                    continue;
                } else {
                    right = mid;
                    mid = left + (right - left) / 2;
                    continue;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums{0};
    auto ans = threeSum(nums);
    return 0;
}