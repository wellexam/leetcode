#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int size = nums.size();
    int count = 0;
    int begin = 0, end = 0;
    nums.emplace_back(k + 1);
    int product = nums[0];
    while (end < size) {
        
    }
}

int main() {
    vector<int> nums{10, 5, 2, 6};
    cout << numSubarrayProductLessThanK(nums, 100);
    return 0;
}