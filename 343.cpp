#include "regular_headers.hpp"

using namespace std;

int integerBreak(int n) {
    if (n == 2) {
        return 1;
    }
    vector<int> dp(n, 0);
    dp[1] = 1;
    dp[2] = 2;
    int current = 3;
    while (current < n) {
        auto max_product = 0;
        for (int i = 1; i <= current / 2; ++i) {
            max_product = max(dp[i] * dp[current - i], max_product);
        }
        if (max_product < current) {
            dp[current] = current;
        } else {
            dp[current] = max_product;
        }
        ++current;
    }
    auto ans = 0;
    for (int i = 1; i <= n / 2; ++i) {
        ans = max(dp[i] * dp[n - i], ans);
    }
    return ans;
}