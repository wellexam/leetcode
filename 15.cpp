#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    if (size < 3) {
        return {};
    }
    vector<vector<int>> ans;
    int left = 0, mid = 1, right = size - 1;
    while (left <= size - 3) {
        while (mid < right) {
            int sum = nums[left] + nums[mid] + nums[right];
            if (sum == 0) {
                ans.push_back({nums[left], nums[mid], nums[right]});
                while (right > mid) {
                    if (nums[mid + 1] != nums[mid]) {
                        ++mid;
                        break;
                    } else {
                        ++mid;
                    }
                }
                continue;
            } else if (sum > 0) {
                while (right > mid) {
                    if (nums[right - 1] != nums[right]) {
                        --right;
                        break;
                    } else {
                        --right;
                    }
                }
                continue;
            } else {
                while (right > mid) {
                    if (nums[mid + 1] != nums[mid]) {
                        ++mid;
                        break;
                    } else {
                        ++mid;
                    }
                }
                continue;
            }
        }
        while (left <= size - 3) {
            if (nums[left + 1] != nums[left]) {
                ++left;
                break;
            } else {
                ++left;
            }
        }
        mid = left + 1;
        right = size - 1;
    }
    return ans;
}