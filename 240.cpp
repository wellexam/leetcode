#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    const int m = matrix.size(), n = matrix[0].size();
    int x = m - 1, y = 0;
    for (; x >= 0 && y < n;) {
        if (matrix[x][y] > target) {
            --x;
            continue;
        }
        if (matrix[x][y] < target) {
            ++y;
            continue;
        }
        if (matrix[x][y] == target)
            return true;
    }
    return false;
}

int main() {
    vector<vector<int>> a = {{-1, 3}};
    bool ans = searchMatrix(a, 3);
    cout << ans;
}