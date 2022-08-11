#include "regular_headers.hpp"

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if (sum % 2)
        return false;
    vector<vector<int>> dp(nums.size() + 1, vector<int>((sum >> 1) + 1, 0));
    for (int i = 1; i <= nums.size(); i++) {
        for (int j = 1; j <= sum / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
        }
    }
    return (dp.back())[sum / 2] == sum / 2;
}

int main() {
    vector<int> nums{1, 5, 11, 5};
    cout << canPartition(nums);
    return 0;
}