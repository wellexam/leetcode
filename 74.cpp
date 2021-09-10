#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size(), size = m * n;
    int first = 1, last = size, current = (first + last) >> 1;
    if (matrix[m - 1][n - 1] < target) {
        return false;
    } else if (matrix[m - 1][n - 1] == target) {
        return true;
    }
    while (first <= last) {
        int x = (current - 1) / n, y = current - x * n - 1;
        if (matrix[x][y] < target) {
            if (first != current) {
                first = current;
                current = (first + last) >> 1;
            } else {
                break;
            }
        } else if (matrix[x][y] > target) {
            if (last != current) {
                last = current;
                current = (first + last) >> 1;
            } else {
                break;
            }
        } else {
            return true;
        }
    }
    return false;
}