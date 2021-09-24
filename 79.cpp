#include "regular_headers.hpp"

using namespace std;

bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &is_visited, int digit, int x, int y) {
    if (word[digit] != board[x][y]) {
        is_visited[x][y] = false;
        return false;
    }
    if (digit == word.length() - 1) {
        return true;
    }
    is_visited[x][y] = true;
    if (x - 1 >= 0 && !is_visited[x - 1][y] && dfs(board, word, is_visited, digit + 1, x - 1, y)) {
        return true;
    } else if (x + 1 < board.size() && !is_visited[x + 1][y] && dfs(board, word, is_visited, digit + 1, x + 1, y)) {
        return true;
    } else if (y - 1 >= 0 && !is_visited[x][y - 1] && dfs(board, word, is_visited, digit + 1, x, y - 1)) {
        return true;
    } else if (y + 1 < board[0].size() && !is_visited[x][y + 1] && dfs(board, word, is_visited, digit + 1, x, y + 1)) {
        return true;
    }
    is_visited[x][y] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    if (board.empty()) {
        return false;
    }
    int m = board.size(), n = board[0].size();
    vector<bool> temp(n, false);
    vector<vector<bool>> is_visited(m, temp);
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (dfs(board, word, is_visited, 0, x, y)) {
                return true;
            }
        }
    }
    return false;
}