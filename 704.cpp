#include "regular_headers.hpp"

using namespace std;

int search(vector<int> &nums, int target) {
    int begin = 0, end = nums.size() - 1, mid = (begin + end) >> 1;
    if (nums[end] == target) {
        return end;
    }
    while (nums[mid] != target) {
        if (nums[mid] > target) {
            end = mid;
            mid = (begin + end) >> 1;
            if (begin >= end - 1 && nums[end] != target && nums[begin] != target) {
                return -1;
            }
            if (nums[begin] == target) {
                return begin;
            }
            continue;
        } else {
            begin = mid;
            mid = (begin + end) >> 1;
            if (begin >= end - 1 && nums[end] != target && nums[begin] != target) {
                return -1;
            }
            if (nums[end] == target) {
                return end;
            }
            continue;
        }
    }
    return mid;
}

int main() {
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    cout << search(nums, 2);
}