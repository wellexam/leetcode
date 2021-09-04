#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> a = {1}, b = {1, 1};
    for (int i = 3; i <= rowIndex; ++i) {
        if (i % 2 != 0) {
            a.push_back(i - 1);
            a.push_back(1);
            for (int j = 0; j < i; ++j) {
                if (j - 1 >= 0) {
                    a[j] = b[j - 1];
                    if (j + 1 < i) {
                        a[j] += b[j];
                    }
                } else {
                    a[j] = b[j];
                }
            }
        } else {
            b.push_back(i - 1);
            b.push_back(1);
            for (int j = 0; j < i; ++j) {
                if (j - 1 >= 0) {
                    b[j] = a[j - 1];
                    if (j + 1 < i) {
                        b[j] += a[j];
                    }
                } else {
                    b[j] = a[j];
                }
            }
        }
    }
    return rowIndex % 2 ? a : b;
}

int main() {
    auto ans = getRow(4);
    for (auto i : ans) {
        cout << i << " ";
    }
}