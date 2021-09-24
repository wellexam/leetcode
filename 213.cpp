#include "regular_headers.hpp"

using namespace std;

int money_even(vector<int> &nums){
    auto sum_1 = 0, sum_2 = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum_1 += nums[i];
    }
    for (int i = 1; i < nums.size(); i += 2) {
        sum_2 += nums[i];
    }
    return max(sum_1, sum_2);
}

int money_odd(vector<int> &nums) {}

int rob(vector<int> &nums) {
    int n = nums.size();
    if (!n % 2) {
        return money_even(nums);
    } else {
        return money_odd(nums);
    }
}