#include "regular_headers.hpp"

using namespace std;

int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();
    auto last = false;
    vector<int> count;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; ++i) {
        if (dp[i - 1] && nums[i] - nums[i - 1] == nums[i - 1] - nums[i -  2]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            if (last) {
                count.emplace_back(dp[i - 1]);
                last = false;
            }
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = 3;
                last = true;
            }
        }
    }
    if (last) {
        count.emplace_back(dp[n - 1]);
    }
    auto ans = 0;
    for (auto &i : count) {
        for (int j = i; j >= 3; --j) {
            ans += i - j + 1;
        }
    }
    return ans;
}