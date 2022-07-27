#include "regular_headers.hpp"

using namespace std;

int numDistinct(string s, string t) {
    vector<vector<unsigned long>> dp(s.size() + 1, vector<unsigned long>(t.size() + 1, 0));
    for (int j = 0; j < dp[0].size(); j++) {
        dp[0][j] = 0;
    }
    for (int i = 0; i < dp.size(); i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp.back().back();
}

int main() {
    string s = "rabbbit";
    string t = "rabbit";
    cout << numDistinct(s, t);
    return 0;
}