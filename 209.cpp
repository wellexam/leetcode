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
    // sum += nums[end];
    while (end < size) {
        sum += nums[end];
        if (sum >= target) {
            break;
        }
    }
    if (sum < target) {
        return 0;
    }
    min_len = end - begin + 1;
    
}