#include "regular_headers.hpp"

using namespace std;

void nextPermutation(vector<int> &nums) {
    int current = nums.size();
    current--;
    while (current > 0) {
        if (nums[current] <= nums[current - 1]) {
            --current;
            continue;
        }
        sort(nums.begin() + current, nums.end());
        int shit = current;
        while (nums[shit] <= nums[current - 1]) {
            shit++;
        }
        swap(nums[shit], nums[current - 1]);
        break;
    }
    if (current == 0) {
        sort(nums.begin(), nums.end());
    }
    return;
}

int main() {
    vector<int> nums{1, 2, 3};
    nextPermutation(nums);
    return 0;
}