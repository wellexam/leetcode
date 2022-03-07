#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void down(vector<int> &nums, int x, int n) {
    int current = x;
    while (current < n) {
        if (current * 2 < n) {
            if (current * 2 + 1 < n) {
                if (nums[current] < max(nums[current * 2], nums[current * 2 + 1])) {
                    if (nums[current * 2] > nums[current * 2 + 1]) {
                        swap(nums[current], nums[current * 2]);
                        current = current * 2;
                        continue;
                    } else {
                        swap(nums[current], nums[current * 2 + 1]);
                        current = current * 2 + 1;
                        continue;
                    }
                }
            } else {
                if (nums[current] < nums[current * 2]) {
                    swap(nums[current], nums[current * 2]);
                    current = current * 2;
                    continue;
                }
            }
        }
        break;
    }
}

int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    for (int i = (nums.size() + 1) / 2; i >= 0; i--) {
        down(nums, i, n);
    }
    int count = 0;
    while (count < k) {
        swap(nums[0], nums[nums.size() - count - 1]);
        down(nums, 0, n - count - 1);
        count++;
    }
    return nums[nums.size() - k];
}

int main() {
    vector<int> nums{-1, 2, 0};
    cout << findKthLargest(nums, 3);
    return 0;
}