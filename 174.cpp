#include "regular_headers.hpp"

int calculateMinimumHP(vector<vector<int>> &dungeon) {
    vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
    dp.back().back() = max(1, 1 - dungeon.back().back());
    for (int j = dp[0].size() - 2; j >= 0; j--) {
        dp.back()[j] = max(1, dp.back()[j + 1] - dungeon.back()[j]);
    }
    for (int i = dp.size() - 2; i >= 0; i--) {
        dp[i].back() = max(1, dp[i + 1].back() - dungeon[i].back());
    }
    for (int i = dp.size() - 2; i >= 0; i--) {
        for (int j = dp[0].size() - 2; j >= 0; j--) {
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << calculateMinimumHP(dungeon);
}