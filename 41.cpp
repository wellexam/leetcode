#include "regular_headers.hpp"

int firstMissingPositive(vector<int> &nums) {
    vector<bool> hash(nums.size() + 1, false);
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (num < 1 || num > nums.size()) {
            hash.back() = true;
        } else {
            hash[num - 1] = true;
        }
    }
    for (int i = 0; i < static_cast<int>(hash.size()) - 1; i++) {
        if (!hash[i]) {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main() {
    vector<int> nums{1, 2, 0};
    cout << firstMissingPositive(nums);
}