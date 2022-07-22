#include "regular_headers.hpp"

using namespace std;

void ksort(int left, int right, vector<int> &nums) {
    if (left >= right) {
        return;
    }
    int i = left, j = right, flag = nums[i + ((j - i) >> 1)];
    swap(nums[i + ((j - i) >> 1)], nums[i]);
    while (i < j) {
        while (nums[j] >= flag && i < j) {
            j--;
        }
        while (nums[i] <= flag && i < j) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    ksort(left, i, nums);
    ksort(i + 1, right, nums);
    return;
}

vector<int> sortArray(vector<int> &nums) {
    ksort(0, nums.size() - 1, nums);
    return nums;
}

int main() {
    vector<int> nums{5, 1, 1, 2, 0, 0};
    sortArray(nums);
    for (auto &i : nums) {
        cout << i << ' ';
    }
    return 0;
}