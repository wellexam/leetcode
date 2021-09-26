#include "regular_headers.hpp"

using namespace std;

int findNumberOfLIS(vector<int> &nums) {
    auto n = nums.size();
    vector<pair<int, int>> dp{n, {0, 1}};
    dp[0].first = 1;
    int current = 1;
    int max_len = 1;
    int first = 0;
    while (current < n) {
        int max_num = 0;
        auto first_pos = current + 1;
        for (int i = 0; i < current; ++i) {
            if (nums[i] < nums[current] && dp[i].first > max_num) {
                max_num = dp[i].first;
                first_pos = i;
            }
        }
        auto sum = 0;
        for (int i = current; i >= first_pos; --i) {
            if (dp[i].first == max_num) {
                sum += dp[i].second;
            }
        }
        dp[current].first = max_num + 1;
        dp[current].second = max(sum, 1);
        auto temp = max_len;
        max_len = max(dp[current].first, max_len);
        if (max_len != temp) {
            first = first_pos;
        }
        ++current;
    }
    auto count = 0;
    for (int i = first; i < n; ++i) {
        if (dp[i].first == max_len) {
            count += dp[i].second;
        }
    }
    return count;
}