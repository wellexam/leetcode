#include "regular_headers.hpp"

int splitArray(vector<int> &nums, int m) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = nums[i - 1] + prefix[i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(m, i); j++) {
            for (int k = 0; k < i; k++) {
                int sub = prefix[i] - prefix[k];
                dp[i][j] = min(dp[i][j], max(sub, dp[k][j - 1]));
            }
        }
    }
    return dp[n][m];
}

// int splitArray(vector<int> &nums, int m) {
//     int n = nums.size();
//     vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
//     vector<long long> sub(n + 1, 0);
//     for (int i = 0; i < n; i++) {
//         sub[i + 1] = sub[i] + nums[i];
//     }
//     f[0][0] = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= min(i, m); j++) {
//             for (int k = 0; k < i; k++) {
//                 f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
//             }
//         }
//     }
//     return (int)f[n][m];
// }

int main() {
    vector<int> nums{7, 2, 5, 10, 8};
    cout << splitArray(nums, 2);
    return 0;
}