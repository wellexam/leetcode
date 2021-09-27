#include "regular_headers.hpp"

using namespace std;

int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount, amount);
    sort(coins.begin(), coins.end());
    for (auto &i : coins) {
        if (i >= amount) {
            break;
        }
        dp[i] = 1;
    }
    int current = 1;
}