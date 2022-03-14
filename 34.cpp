#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) {
        return {-1, -1};
    }
    int left = 0, right = nums.size(), mid = left + (right - left) / 2;
    while (left < right) {
        if (nums[mid] == target) {
            break;
        }
        if (nums[mid] < target) {
            left = mid + 1;
            mid = left + (right - left) / 2;
        } else {
            right = mid;
            mid = left + (right - left) / 2;
        }
    }
    if (nums[mid] != target) {
        return {-1, -1};
    }
    int start = 0, end = 0;
    int i = 0, j = mid + 1, k = i + (j - i) / 2;
    while (i < j) {
        if (nums[k] == target) {
            if (k > 0 && nums[k - 1] != target) {
                start = k;
                break;
            }
            if (k == 0) {
                start = 0;
                break;
            }
            j = k;
            k = i + (j - i) / 2;
            continue;
        }
        if (nums[k] > target) {
            j = k;
            k = i + (j - i) / 2;
        } else {
            i = k + 1;
            k = i + (j - i) / 2;
        }
    }
    i = mid, j = nums.size(), k = i + (j - i) / 2;
    while (i < j) {
        if (nums[k] == target) {
            if (k < nums.size() - 1 && nums[k + 1] != target) {
                end = k;
                break;
            }
            if (k == nums.size() - 1) {
                end = k;
                break;
            }
            i = k + 1;
            k = i + (j - i) / 2;
        }
        if (nums[k] > target) {
            j = k;
            k = i + (j - i) / 2;
        } else {
            i = k + 1;
            k = i + (j - i) / 2;
        }
    }
    return {start, end};
}

int main() {
    vector<int> nums{2, 2};
    auto ans = searchRange(nums, 3);
    return 0;
}