#include "regular_headers.hpp"

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    vector<int> tails;
    tails.reserve(nums.size());
    tails.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (tails.back() < nums[i]) {
            tails.push_back(nums[i]);
            continue;
        }
        int length = tails.size();
        int left = 0, right = length, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (tails[mid] == nums[i]) {
                break;
            }
            if (mid > 0 && tails[mid - 1] < nums[i] && tails[mid] > nums[i]) {
                tails[mid] = nums[i];
                break;
            }
            if (mid == 0 && tails[mid] > nums[i]) {
                tails[mid] = nums[i];
                break;
            }
            if (tails[mid] > nums[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return tails.size();
}

int main() {
    vector<int> nums{1, 3, 6, 7, 9, 4, 10, 5, 6};
    auto ans = lengthOfLIS(nums);
    return 0;
}