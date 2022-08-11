#include "regular_headers.hpp"

unordered_map<int, bool> visited;

inline bool isVisited(int hash_code) {
    if (!visited[hash_code]) {
        visited[hash_code] = true;
        return false;
    } else {
        return true;
    }
}

int encode(vector<vector<int>> &board) {
    int offset = 0;
    int hash_code = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            hash_code += (board[i][j] << (offset * 3));
            offset++;
        }
    }
    return hash_code;
}

vector<vector<int>> decode(int hash_code) {
    vector<vector<int>> board(2, vector<int>(3));
    int mask = 7;
    int offset = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = (hash_code & mask) >> (offset * 3);
            mask <<= 3;
            offset++;
        }
    }
    return board;
}

int slidingPuzzle(vector<vector<int>> &board) {
    deque<int> que, que_next;
    vector<vector<int>> target_{{1, 2, 3}, {4, 5, 0}};
    int target = encode(target_);
    int count = 0;
    que.push_back(encode(board));
    while (!que.empty()) {
        while (!que.empty()) {
            int cur = que.front();
            que.pop_front();
            if (cur == target) {
                return count;
            }
            auto temp = decode(cur);
            int x = 0, y = 0;
            for (; x < 2; x++) {
                bool flag = false;
                for (y = 0; y < 3; y++) {
                    if (!temp[x][y]) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (x > 0) {
                swap(temp[x][y], temp[x - 1][y]);
                int hash_code = encode(temp);
                if (!isVisited(hash_code)) {
                    que_next.push_back(hash_code);
                }
                swap(temp[x][y], temp[x - 1][y]);
            }
            if (x < 1) {
                swap(temp[x][y], temp[x + 1][y]);
                int hash_code = encode(temp);
                if (!isVisited(hash_code)) {
                    que_next.push_back(hash_code);
                }
                swap(temp[x][y], temp[x + 1][y]);
            }
            if (y > 0) {
                swap(temp[x][y], temp[x][y - 1]);
                int hash_code = encode(temp);
                if (!isVisited(hash_code)) {
                    que_next.push_back(hash_code);
                }
                swap(temp[x][y], temp[x][y - 1]);
            }
            if (y < 2) {
                swap(temp[x][y], temp[x][y + 1]);
                int hash_code = encode(temp);
                if (!isVisited(hash_code)) {
                    que_next.push_back(hash_code);
                }
                swap(temp[x][y], temp[x][y + 1]);
            }
        }
        que.swap(que_next);
        count++;
    }
    return -1;
}

int main() {
    vector<vector<int>> board{{1, 2, 3}, {5, 4, 0}};
    cout << slidingPuzzle(board);
    return 0;
}