#include "regular_headers.hpp"

using namespace std;

int jump(vector<int> &nums) {
    int farthest = 0;
    int current = 0;
    int step = 0;
    while (current < nums.size() - 1) {
        farthest = nums[current] + current;
        int temp_far = farthest;
        for (int i = current + 1; i <= farthest && i < nums.size(); i++) {
            if (nums[i] + i >= temp_far) {
                temp_far = nums[i] + i;
                current = i;
            }
        }
        step++;
        if (farthest >= nums.size() - 1) {
            return step;
        }
    }
    return step;
}

int main() {
    vector<int> nums{2, 3, 1};
    cout << jump(nums);
    return 0;
}