#include "regular_headers.hpp"

using namespace std;

int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n, 0);
    if (s[0] == '0') {
        return 0;
    }
    dp[0] = 1;
    if (n >= 2) {
        if (s[1] == '0') {
            if (s[0] == '1' || s[0] == '2') {
                dp[1] = dp[0];
            } else {
                return 0;
            }
        } else {
            auto sum = (s[0] - '0') * 10 + s[1] - '0';
            if (sum <= 26 && sum > 9) {
                dp[1] = 1 + dp[0];
            } else {
                dp[1] = dp[0];
            }
        }
    }
    auto current = 2;
    while (current < n) {
        auto cur = s[current] - '0', prev = s[current - 1] - '0';
        if (cur == 0) {
            if (prev == 1 || prev == 2) {
                dp[current] = dp[current - 2];
            } else {
                return 0;
            }
        } else {
            auto sum = prev * 10 + cur;
            if (sum <= 26 && sum > 9) {
                dp[current] = dp[current - 1] + dp[current - 2];
            } else {
                dp[current] = dp[current - 1];
            }
        }
        ++current;
    }
    return dp[n - 1];
}