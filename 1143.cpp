#include "regular_headers.hpp"

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int size_1 = text1.size(), size_2 = text2.size();
    vector<int> temp(size_2, -1);
    vector<vector<int>> dp(size_1, temp);
    if (text1[0] == text2[0]) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for (int i = 0; i < size_1; ++i) {
        auto char1 = text1[i];
        for (int j = 0; j < size_2; ++j) {
            auto char2 = text2[j];
            if (char1 == char2) {
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 1;
                }
            } else {
                auto a = 0, b = 0;
                if (i > 0) {
                    a = dp[i - 1][j];
                }
                if (j > 0) {
                    b = dp[i][j - 1];
                }
                dp[i][j] = max(a, b);
            }
        }
    }
    return dp[size_1 - 1][size_2 - 1];
}

int main() {
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}