#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> triangle;
    triangle.reserve(rowIndex);
    triangle.emplace_back(vector<int>({1}));
    for (int i = 1; i <= rowIndex; i++) {
        triangle.emplace_back(vector<int>(i + 1, 1));
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle[rowIndex];
}

int main() {
    auto ans = getRow(0);
    for (auto i : ans) {
        cout << i << " ";
    }
}