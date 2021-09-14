#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int product_cal(int i, int j, vector<vector<int>> &product) {
    if (j > i) {
        if (product[i][j]) {
            return product[i][j];
        } else {
            product_cal(i, j - 1, product);
            product[i][j] = product[i][j - 1] * product[j][j];
            return product[i][j];
        }
    } else if (i == j) {
        return product[i][j];
    } else {
        return 0;
    }
}

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> temp(size, 0);
    vector<vector<int>> product(size, temp);
    for (int i = 0; i < size; ++i) {
        product[i][i] = nums[i];
    }
    int begin = 0, end = 0;
    while (end < size) {
        int current = product_cal(begin, end, product);
        if (current < k) {
            ++end;
        } else if (begin < end) {
            auto temp_begin = begin;
            while (temp_begin <= end) {
                product_cal(temp_begin, end, product);
                ++temp_begin;
            }
        } else {
            ++begin;
            ++end;
        }
    }
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (product[i][j] >= k || !product[i][j]) {
                break;
            } else {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums{10, 5, 2, 6};
    cout << numSubarrayProductLessThanK(nums, 100);
    return 0;
}