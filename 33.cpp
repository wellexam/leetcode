#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
    int size = nums.size();
    int first = 0, last = size - 1, current = 0;
    if (nums[last] < nums[0]) {
        if (size - 1 > 0 && nums[size - 1] < nums[size - 2]) {
            current = size - 1;
        } else {
            current = (first + last) >> 1;
            while (first <= last) {
                if (current >= 1 && nums[current] < nums[current - 1]) {
                    break;
                } else if (nums[current] < nums[0]) {
                    if (last != current) {
                        last = current;
                        current = (first + last) >> 1;
                    } else {
                        break;
                    }
                } else if (nums[current] > nums[0]) {
                    if (first != current) {
                        first = current;
                        current = (first + last) >> 1;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    auto if_find = false;
    if (target < nums[current] || (current > 0 && target > nums[current - 1])) {
        return -1;
    }
    if (!current) {
        first = 0, last = size - 1, current = (first + last) >> 1;
    } else if (target < nums[0]) {
        first = current, last = size - 1, current = (first + last) >> 1;
    } else {
        first = 0, last = current, current = (first + last) >> 1;
    }
    if (nums[last] == target) {
        return last;
    }
    while (first <= last) {
        if (nums[current] > target) {
            if (last != current) {
                last = current;
                current = (first + last) >> 1;
            } else {
                break;
            }
        } else if (nums[current] < target) {
            if (first != current) {
                first = current;
                current = (first + last) >> 1;
            } else {
                break;
            }
        } else {
            if_find = true;
            break;
        }
    }
    if (if_find) {
        return current;
    }
    return -1;
}