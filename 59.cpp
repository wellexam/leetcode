#include <iostream>
#include <vector>

using namespace std;

void recursive(vector<vector<int>> &mat, int origin, int &current) {
    int n = mat.size();
    int length = n - origin * 2;
    pair<int, int> pos{origin, origin};
    for (int i = 0; i < length - 1; i++) {
        mat[pos.first][pos.second + i] = current++;
    }
    pos = {origin, origin + length - 1};
    for (int i = 0; i < length - 1; i++) {
        mat[pos.first + i][pos.second] = current++;
    }
    pos = {origin + length - 1, origin + length - 1};
    for (int i = 0; i < length - 1; i++) {
        mat[pos.first][pos.second - i] = current++;
    }
    pos = {origin + length - 1, origin};
    for (int i = 0; i < length - 1; i++) {
        mat[pos.first - i][pos.second] = current++;
    }
    return;
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int current = 1;
    for (int origin = 0; origin <= n / 2; origin++) {
        recursive(ans, origin, current);
    }
    if (n % 2) {
        ans[n / 2][n / 2] = n * n;
    }
    return ans;
}

int main() {
    auto ans = generateMatrix(3);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}