#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j + i < n - 1 - i; ++j) {
            int a = matrix[i + j][n - 1 - i];
            matrix[i + j][n - 1 - i] = matrix[i][i + j];
            int b = matrix[n - 1 - i][n - 1 - i - j];
            matrix[n - 1 - i][n - 1 - i - j] = a;
            int c = matrix[n - 1 - j - i][i];
            matrix[n - 1 - j - i][i] = b;
            matrix[i][i + j] = c;
        }
    }
}

int main() {
    vector<vector<int>> mat = {{5, 1, 9, 11},
                               {2, 4, 8, 10},
                               {13, 3, 6, 7},
                               {15, 14, 12, 16}};
    rotate(mat);
    for (const auto &i : mat) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}