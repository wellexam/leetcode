#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int size = nums.size();
    int min_len = size + 1;
    int begin = 0, end = 0;
    int sum = 0;
    while (end < size) {
        sum += nums[end];
        if (sum >= target) {
            break;
        }
        ++end;
    }
    if (sum < target) {
        return 0;
    }
    while (begin <= end && sum - nums[begin] >= target) {
        sum -= nums[begin];
        ++begin;
    }
    min_len = end - begin + 1;
    while (true) {
        sum -= nums[begin];
        ++begin;
        ++end;
        if (end < size) {
            sum += nums[end];
        }
        while (begin < size && sum - nums[begin] >= target) {
            sum -= nums[begin];
            ++begin;
        }
        if (end == size) {
            break;
        }
    }
    min_len = end - begin + 1;
    if (end == size) {
        sum -= 1;
    }
    return min_len;
}