#include "regular_headers.hpp"

int findRotateSteps(string ring, string key) {
    vector<vector<int>> dp(ring.size(), vector<int>(key.size(), 0));
    unordered_map<char, vector<int>> umap;
    for (int i = 0; i < ring.size(); i++) {
        umap[ring[i]].push_back(i);
    }
    for (auto i : umap[key[0]]) {
        dp[i][0] = min(i, int(ring.size() - i)) + 1;
    }
    for (int j = 1; j < key.size(); j++) {
        for (auto dest : umap[key[j]]) {
            int min_dist = INT32_MAX;
            for (auto i : umap[key[j - 1]]) {
                if (dest <= i) {
                    min_dist = min(min_dist, min(i - dest, int(ring.size() - i + dest)) + dp[i][j - 1]);
                } else {
                    min_dist = min(min_dist, min(dest - i, int(i + ring.size() - dest)) + dp[i][j - 1]);
                }
            }
            dp[dest][j] = min_dist + 1;
        }
    }
    int ans = INT32_MAX;
    for (auto i : umap[key.back()]) {
        ans = min(ans, dp[i][key.size() - 1]);
    }
    return ans;
}

int main() {
    string ring = "edcba";
    string key = "abcde";
    cout << findRotateSteps(ring, key);
    return 0;
}