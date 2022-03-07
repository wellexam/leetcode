#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums) {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            swap(nums[p0], nums[i]);
            if (p1 > p0) {
                swap(nums[p1], nums[i]);
            }
            ++p0;
            ++p1;
        } else if (nums[i] == 1) {
            swap(nums[i], nums[p1]);
            p1++;
        }
    }
    return;
}

int main() {
    vector<int> nums = {1, 0};
    sortColors(nums);
    return 0;
}