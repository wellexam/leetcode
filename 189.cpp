#include "regular_headers.hpp"

void rotate(vector<int> &nums, int k) {
    int len = int(nums.size());
    k %= len;
    if (k == 0)
        return;
    int count = 0;
    int offset = 0;
    while (count < len) {
        int index = (0 + k + offset) % len;
        int prev = nums[offset];
        while (index != offset) {
            int temp = nums[index];
            nums[index] = prev;
            prev = temp;
            index = (index + k) % len;
            count++;
        }
        nums[index] = prev;
        count++;
        offset++;
    }
    return;
}

int main() {
    vector<int> nums{1, 2, 3};
    rotate(nums, 2);
    return 0;
}