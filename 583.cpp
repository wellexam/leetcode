#include "regular_headers.hpp"

using namespace std;

int minDistance(string word1, string word2) {
    int size_1 = word1.size(), size_2 = word2.size();
    vector<int> temp(size_2, -1);
    vector<vector<int>> dp(size_1, temp);
    if (word1[0] == word2[0]) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for (int i = 0; i < size_1; ++i) {
        auto char1 = word1[i];
        for (int j = 0; j < size_2; ++j) {
            auto char2 = word2[j];
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
    return size_1 + size_2 - 2 * dp[size_1 - 1][size_2 - 1];
}