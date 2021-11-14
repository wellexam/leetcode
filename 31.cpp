#include "regular_headers.hpp"

using namespace std;

void nextPermutation(vector<int> &nums) {
    int size = nums.size();
    int flag = 0;
    for (int i = size - 1; i > 0; --i) {
        if (nums[i] > nums[i - 1]) {
            flag = i;
            break;
        }
    }
    int flag2 = 0;
    if (flag) {
        for (int i = size - 1; i >= flag; --i) {
            if (nums[i] > nums[flag - 1]) {
                flag2 = i;
                break;
            }
        }
    }
    if (flag && flag2) {
        swap(nums[flag2], nums[flag - 1]);
        sort(nums.begin() + flag, nums.end());
    } else {
        sort(nums.begin(), nums.end());
    }
}