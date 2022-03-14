#include "regular_headers.hpp"

using namespace std;

void ksort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = left + rand() % (right - left + 1);
    int flag = nums[pivot];
    swap(nums[left], nums[pivot]);
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= flag) {
            j--;
        }
        while (i < j && nums[i] <= flag) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    ksort(nums, left, i);
    ksort(nums, i + 1, right);
}

vector<int> sortArray(vector<int> &nums) {
    srand(time(0));
    ksort(nums, 0, nums.size() - 1);
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