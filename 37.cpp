#include "regular_headers.hpp"

using namespace std;

vector<vector<char>> board_;

inline bool checkMatrix(int x, int y) {
    int x1, y1, x2, y2;
    x1 = (x / 3) * 3;
    y1 = (y / 3) * 3;
    x2 = x1 + 2;
    y2 = y1 + 2;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (board_[i][j] == board_[x][y] && (i != x || j != y)) {
                return false;
            }
        }
    }
    return true;
}

inline bool checkCol(int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (board_[i][y] == board_[x][y] && i != x) {
            return false;
        }
    }
    return true;
}

inline bool checkRow(int x, int y) {
    for (int j = 0; j < 9; j++) {
        if (board_[x][j] == board_[x][y] && j != y) {
            return false;
        }
    }
    return true;
}

inline pair<int, int> next(int x, int y) {
    if (y < 9) {
        return {x, y + 1};
    } else {
        return {x + 1, 0};
    }
}

bool check(int x, int y) {
    // for (auto &s : board_) {
    //     for (auto c : s) {
    //         cout << c << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    if (x == 9) {
        return true;
    }
    while (x < 9 && board_[x][y] != '.') {
        auto temp = next(x, y);
        x = temp.first;
        y = temp.second;
    }
    if (x == 9)
        return true;
    // if (x == 8 && y == 8) {
    //     if (board_[x][y] != '.')
    //         return true;
    // }
    // assert(board_[x][y] == '.');
    for (char ch = '1'; ch <= '9'; ch++) {
        board_[x][y] = ch;
        if (checkCol(x, y) && checkRow(x, y) && checkMatrix(x, y)) {
            if (check(next(x, y).first, next(x, y).second)) {
                return true;
            }
        }
        // if (checkCol(x, y)) {
        //     if (checkRow(x, y)) {
        //         if (checkMatrix(x, y)) {
        //             if (check(next(x, y).first, next(x, y).second)) {
        //                 return true;
        //             }
        //         }
        //     }
        // }
    }
    board_[x][y] = '.';
    return false;
}

void solveSudoku(vector<vector<char>> &board) {
    board_.swap(board);
    check(0, 0);
    board.swap(board_);
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