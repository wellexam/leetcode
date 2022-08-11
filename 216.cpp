#include "regular_headers.hpp"

vector<bool> used;

vector<vector<int>> anses;

vector<int> ans;

set<int> Set;

int K, N;

void recursive(int i, int sum, int temp) {
    for (int j = 1; j <= 9; j++) {
        if (!used[j]) {
            if ((sum + j) <= N) {
                ans[i] = j;
                used[j] = true;
                temp |= (1 << j);
            } else {
                continue;
            }
            if (ans.size() == i + 1) {
                if (sum + j == N && !Set.count(temp)) {
                    anses.push_back(ans);
                    Set.insert(temp);
                }
            } else {
                recursive(i + 1, sum + j, temp);
            }
            temp &= ~(1 << j);
            used[j] = false;
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    used = vector<bool>(10, false);
    ans = vector<int>(k, 0);
    K = k;
    N = n;
    recursive(0, 0, 0);
    return anses;
}

int main() {
    combinationSum3(3, 9);
    return 0;
}