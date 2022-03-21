#include "regular_headers.hpp"

using namespace std;

int maxSubArray(vector<int> &nums) {
    int min_sum = 0, ans = nums[0];
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    return ans;
}

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(nums);
    return 0;
}