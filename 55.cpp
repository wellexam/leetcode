#include "regular_headers.hpp"

using namespace std;

bool canJump(vector<int> &nums) {
    int max = 0;
    int current = 0;
    while (current <= max && current < nums.size()) {
        max = std::max(nums[current] + current, max);
        ++current;
    }
    if (current == nums.size()) {
        return true;
    }
    return false;
}