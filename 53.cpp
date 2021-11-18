#include "regular_headers.hpp"

using namespace std;

int maxSubArray(vector<int> &nums) {
    auto size = nums.size();
    int ans = nums[0], min = nums[0];
    for (int i = 1; i < size; ++i) {
        nums[i] = nums[i - 1] + nums[i];
        if (min > nums[i - 1]) {
            min = nums[i - 1];
        }
        if (min >= 0) {
            ans = ans > nums[i] ? ans : nums[i];
        } else {
            ans = ans > nums[i] - min ? ans : nums[i] - min;
        }
    }
    return ans;
}