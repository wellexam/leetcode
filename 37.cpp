#include "regular_headers.hpp"

using namespace std;

void construct(int k, vector<vector<char>> &board, vector<set<char>> &sets, vector<pair<int, int>> &blanks) {
    sets[k].clear();
    set<char> temp;
    int i = blanks[k].first, j = blanks[k].second;
    auto row = i / 3;
    auto col = j / 3;
    for (int a = row * 3; a < row * 3 + 3; ++a) {
        for (int b = col * 3; b < col * 3 + 3; ++b) {
            temp.insert(board[a][b]);
        }
    }
    for (int a = 0; a < 9; ++a) {
        temp.insert(board[a][j]);
        temp.insert(board[i][a]);
    }
    temp.erase('.');
    for (int x = 1; x <= 9; ++x) {
        if (temp.find(x + '0') == temp.end()) {
            sets[k].insert(x + '0');
        }
    }
}

void solveSudoku(vector<vector<char>> &board) {
    vector<pair<int, int>> blanks;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                blanks.emplace_back(i, j);
            }
        }
    }
    vector<set<char>> sets(blanks.size());
    int count = 0, last = 0;
    construct(0, board, sets, blanks);
    while (count < blanks.size()) {
        int i = blanks[count].first, j = blanks[count].second;
        if (last < count) {
            construct(count, board, sets, blanks);
        }
        last = count;
        if (board[i][j] != '.') {
            auto key = sets[count].upper_bound(board[i][j]);
            if (key == sets[count].end()) {
                board[i][j] = '.';
                --count;
                continue;
            }
            board[i][j] = *key;
            ++count;
            continue;
        } else {
            auto key = sets[count].begin();
            if (key == sets[count].end()) {
                board[i][j] = '.';
                --count;
                continue;
            }
            board[i][j] = *key;
            ++count;
            continue;
        }
    }
    return;
}

int main() {
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    for (auto &i : board) {
        for (auto &c : i) {
            cout << c << ' ';
        }
        cout << endl;
    }
}