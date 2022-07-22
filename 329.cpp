#include "regular_headers.hpp"

vector<vector<int>> mem;

int dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &mem) {
    if (mem[x][y]) {
        return mem[x][y];
    }
    int ret = 0;
    if (x > 0 && matrix[x - 1][y] > matrix[x][y]) {
        ret = max(ret, dfs(x - 1, y, matrix, mem));
    }
    if (x < matrix.size() - 1 && matrix[x + 1][y] > matrix[x][y]) {
        ret = max(ret, dfs(x + 1, y, matrix, mem));
    }
    if (y > 0 && matrix[x][y - 1] > matrix[x][y]) {
        ret = max(ret, dfs(x, y - 1, matrix, mem));
    }
    if (y < matrix.front().size() - 1 && matrix[x][y + 1] > matrix[x][y]) {
        ret = max(ret, dfs(x, y + 1, matrix, mem));
    }
    mem[x][y] = ret + 1;
    return mem[x][y];
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
    auto mem = vector<vector<int>>{matrix.size(), vector<int>(matrix.front().size(), 0)};
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            ans = max(ans, dfs(i, j, matrix, mem));
        }
    }
    return ans;
}