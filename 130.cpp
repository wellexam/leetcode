#include "regular_headers.hpp"

using namespace std;

void dfs(int x, int y, vector<vector<char>> &board, unordered_map<int, bool> &map) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] = 'S';
        map[x * board[0].size() + y] = true;
        dfs(x - 1, y, board, map);
        dfs(x + 1, y, board, map);
        dfs(x, y - 1, board, map);
        dfs(x, y + 1, board, map);
    } else {
        return;
    }
}

void solve(vector<vector<char>> &board) {
    unordered_map<int, bool> map;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        dfs(i, 0, board, map);
        dfs(i, n - 1, board, map);
    }
    for (int j = 1; j < n - 1; ++j) {
        dfs(0, j, board, map);
        dfs(m - 1, j, board, map);
    }
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    for (auto &i : map) {
        board[i.first / n][i.first % n] = 'O';
    }
}