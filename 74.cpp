#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int left = 0, right = matrix.size(), mid = left + (right - left) / 2;
    bool find_line = false;
    while (left < right) {
        if (mid < matrix.size() - 1 && matrix[mid].front() <= target && matrix[mid + 1].front() > target) {
            find_line = true;
            break;
        }
        if (mid == matrix.size() - 1 && matrix[mid].front() <= target) {
            find_line = true;
            break;
        }
        if (matrix[mid].front() < target) {
            left = mid + 1;
            mid = left + (right - left) / 2;
            continue;
        } else {
            right = mid;
            mid = left + (right - left) / 2;
            continue;
        }
    }
    if (!find_line) {
        return false;
    }
    int row = mid;
    left = 0, right = matrix[0].size(), mid = left + (right - left) / 2;
    while (left < right) {
        if (matrix[row][mid] == target) {
            return true;
        }
        if (matrix[row][mid] < target) {
            left = mid + 1;
            mid = left + (right - left) / 2;
            continue;
        } else {
            right = mid;
            mid = left + (right - left) / 2;
            continue;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix{{1}, {3}};
    cout << searchMatrix(matrix, 3);
    return 0;
}