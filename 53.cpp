#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include "regular_headers.hpp"

using namespace std;

int maxSubArray(vector<int> &nums) {
    vector<int> sum(nums.size(), 0);
    sum[0] = nums[0];
    auto size = nums.size();
    for (int i = 1; i < size; ++i) {
        sum[i] = sum[i - 1] + nums[i];
    }
    int ans = sum[0], min = nums[0];
    for (int i = 1; i < size; ++i) {
        if (min > sum[i - 1]) {
            min = sum[i - 1];
        }
        if (min >= 0) {
            ans = ans > sum[i] ? ans : sum[i];
        } else {
            ans = ans > sum[i] - min ? ans : sum[i] - min;
        }
    }
    return ans;
}

int main() {
    vector<int> nums{-2, -1};
    cout << maxSubArray(nums);
}