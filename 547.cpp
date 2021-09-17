#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int current, vector<vector<int>> &isConnected, vector<bool> &if_visited, int n) {
    if_visited[current] = true;
    for (int i = 0; i < n; ++i) {
        if (!if_visited[i] && isConnected[current][i]) {
            dfs(i, isConnected, if_visited, n);
        }
    }
    return;
}

int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<bool> if_visited(n, false);
    int current = 0, count = 0;
    while (current < n) {
        if (!if_visited[current]) {
            dfs(current, isConnected, if_visited, n);
            ++count;
        }
        ++current;
    }
    return count;
}

int main() {
    vector<vector<int>> shit{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    cout << findCircleNum(shit);
    return 0;
}