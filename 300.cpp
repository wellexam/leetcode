#include "regular_headers.hpp"

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    int current = 1;
    int max_len = 1;
    while (current < n) {
        int max_num = 0;
        for (int i = 0; i < current; ++i) {
            if (nums[i] < nums[current] && dp[i] > max_num) {
                max_num = dp[i];
            }
        }
        dp[current] = max_num + 1;
        ++current;
        max_len = max(dp[current - 1], max_len);
    }
    return max_len;
}

int main() {
    vector<int> nums{1, 3, 6, 7, 9, 4, 10, 5, 6};
    auto ans = lengthOfLIS(nums);
    return 0;
}