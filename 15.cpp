#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int begin = 0, end = nums.size() - 1;
    int last_i = 100001;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] == last_i) {
            continue;
        }
        last_i = nums[i];
        int last_j = 100001;
        for (int j = nums.size() - 1; j >= i + 2; j--) {
            if (nums[j] == last_j) {
                continue;
            }
            last_j = nums[j];
            int target = 0 - nums[i] - nums[j];
            if (target > nums[j]) {
                break;
            }
            if (target < nums[i]) {
                continue;
            }
            int left = i + 1, right = j, mid = left + (right - left) / 2;
            while (left < right) {
                if (nums[mid] == target) {}
            }
        }
    }
}