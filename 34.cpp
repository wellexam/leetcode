#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    int first = 0, last = nums.size() - 1, current = (first + last) >> 2;
    int size = nums.size();
    if (!size) {
        return {-1, -1};
    }
    if (nums[last] == target) {
        current = last;
    } else {
        while (first <= last) {
            if (target < nums[first] || target > nums[last]) {
                return {-1, -1};
            }
            if (nums[current] < target) {
                if (first != current) {
                    first = current;
                    current = (first + last) >> 2;
                } else {
                    return {-1, -1};
                }
            } else if (nums[current] > target) {
                if (last != current) {
                    last = current;
                    current = (first + last) >> 2;
                } else {
                    return {-1, -1};
                }
            } else {
                break;
            }
        }
    }
    int begin = current, end = current;
    while (begin > 0 && nums[begin - 1] == target) {
        --begin;
    }
    while (end < size - 1 && nums[end + 1] == target) {
        ++end;
    }
    return {begin, end};
}