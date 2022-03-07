#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        int length = n - i * 2;
        for (int j = 0; j < length - 1; j++) {
            pair<int, int> a{i, i + j};
            pair<int, int> b{i + j, i + length - 1};
            pair<int, int> c{i + length - 1, i + length - 1 - j};
            pair<int, int> d{i + length - 1 - j, i};
            int temp;
            temp = matrix[a.first][a.second];
            matrix[a.first][a.second] = matrix[d.first][d.second];
            matrix[d.first][d.second] = matrix[c.first][c.second];
            matrix[c.first][c.second] = matrix[b.first][b.second];
            matrix[b.first][b.second] = temp;
        }
    }
}

int main() {
    vector<vector<int>> mat = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(mat);
    for (const auto &i : mat) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}