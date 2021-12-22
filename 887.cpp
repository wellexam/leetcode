#include "regular_headers.hpp"

using namespace std;

vector<vector<int>> table;

void find_mid(int i, int j) {
    int begin = 1, end = j, mid = (begin + end) >> 1;
    while (begin < end) {
        mid = (begin + end) >> 1;
        if (table[i][j - mid] > table[i - 1][mid - 1]) {
            if (begin != mid) {
                begin = mid;
                continue;
            } else {
                break;
            }
        }
        if (table[i][j - mid] < table[i - 1][mid - 1]) {
            if (end != mid) {
                end = mid;
                continue;
            } else {
                break;
            }
        }
        if (table[i][j - mid] == table[i - 1][mid - 1]) {
            table[i][j] = table[i][j - mid] + 1;
            return;
        }
    }
    table[i][j] = min(table[i][j - mid], table[i - 1][mid]) + 1;
}

int superEggDrop(int k, int n) {
    table = vector<vector<int>>(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; ++i) {
        table[i][1] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        table[1][i] = i;
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 2; j <= n; ++j) {
            find_mid(i, j);
        }
    }
    return table[k][n];
}

int main() {
    cout << superEggDrop(6, 1000000);
}