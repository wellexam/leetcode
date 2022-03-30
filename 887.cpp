#include "regular_headers.hpp"

using namespace std;

int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[1][i] = i;
    }
    for (int i = 1; i <= k; i++) {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            int value = n;
            for (int x = 1; x <= j; x++) {
                value = min(value, max(dp[i - 1][x - 1], dp[i][j - x]));
            }
            dp[i][j] = value + 1;
        }
    }
    for (auto &i : dp) {
        for (auto &j : i) {
            cout << j << ' ';
            if (j < 10)
                cout << ' ';
        }
        cout << endl;
    }
    return dp[k][n];
}

int main() {
    cout << superEggDrop(4, 35);
}