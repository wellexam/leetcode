#include "regular_headers.hpp"

using namespace std;

int jump(vector<int> &nums) {
    if (nums.size() == 1) {
        return 0;
    }
    int count = 0;
    int current = 0;
    while (current < nums.size()) {
        int farthest = nums[current] + current;
        if (farthest >= nums.size() - 1) {
            return ++count;
        }
        int next = current + 1;
        int next_farthest = nums[next] + next;
        for (int i = current + 1; i <= farthest && i < nums.size(); i++) {
            if (nums[i] + i > next_farthest) {
                next_farthest = nums[i] + i;
                next = i;
            }
        }
        current = next;
        count++;
    }
    return count;
}

int main() {
    vector<int> nums{2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}