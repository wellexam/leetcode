#include "regular_headers.hpp"

using namespace std;

int numDistinct(string s, string t) {
    vector<vector<unsigned long long>> dp(t.length(), vector<unsigned long long>(s.length(), 0));
    {
        int i = 0;
        auto c = t[i];
        if (c == s[0]) {
            dp[0][0] = 1;
        }
        for (int j = 1; j < s.length(); ++j) {
            if (c != s[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i < t.length(); ++i) {
        auto c = t[i];
        auto flag = (c == t[i - 1]);
        for (int j = i; j < s.length(); ++j) {
            if (c != s[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                if (flag) {
                    if (dp[i - 1][j - 1] == dp[i - 1][j]) {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
    }
    return dp.back().back();
}