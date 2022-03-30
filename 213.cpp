#include "regular_headers.hpp"

using namespace std;

int rob(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = nums[0];
    int ans = max(dp[0], dp[1]);
    for (int i = 2; i < nums.size() - 1; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        ans = max(dp[i], ans);
    }
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        ans = max(dp[i], ans);
    }
    return ans;
}

int main() {
    vector<int> nums{4,1,2,7,5,3,1};
    cout << rob(nums);
}