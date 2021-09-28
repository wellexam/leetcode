#include "regular_headers.hpp"

using namespace std;

int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, -1);
    sort(coins.begin(), coins.end());
    dp[0] = 0;
    int current = coins[0];
    while (current <= amount) {
        int min_amount = 100000;
        for (auto &i : coins) {
            if (i > current) {
                break;
            }
            auto temp = dp[current - i];
            if (temp == -1) {
                continue;
            }
            min_amount = min(temp + 1, min_amount);
        }
        if (min_amount != 100000) {
            dp[current] = min_amount;
        }
        ++current;
    }
    return dp[amount];
}