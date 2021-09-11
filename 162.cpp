#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findPeakElement(vector<int> &nums) {
    int size = nums.size();
    if (size == 1) {
        return 0;
    }
    int left = 0, right = size - 1, current = (left + right) >> 1;
    if (nums[right] > nums[right - 1]) {
        return right; //先判断尾部元素，因为迭代过程中该元素没有机会被查找到。
    }
    while (left <= right) {
        if (current == 0) { //位于头部
            if (nums[current] > nums[current + 1]) {
                return current;
            }
        } else if (current == size - 1) { //位于尾部
            if (nums[current] > nums[current - 1]) {
                return current;
            }
        } else { //中间某元素满足峰值条件
            if (nums[current] > nums[current - 1] && nums[current] > nums[current + 1]) {
                return current;
            }
            if (nums[current - 1] < nums[current] && nums[current + 1] > nums[current]) { //上升趋势，右侧必有峰值。
                if (left != current) {
                    left = current;
                    current = (left + right) >> 1;
                    continue;
                } else {
                    break;
                }
            } else if (nums[current - 1] > nums[current] && nums[current + 1] < nums[current]) { //下降趋势，左侧必有峰值。
                if (right != current) {
                    right = current;
                    current = (left + right) >> 1;
                    continue;
                } else {
                    break;
                }
            } else { //谷值，左右两侧均有峰值，随机选取一侧缩小范围。
                if (rand() % 2) {
                    if (right != current) {
                        right = current;
                        current = (left + right) >> 1;
                        continue;
                    } else if (left != current) {
                        left = current;
                        current = (left + right) >> 1;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    if (left != current) {
                        left = current;
                        current = (left + right) >> 1;
                        continue;
                    } else if (right != current) {
                        right = current;
                        current = (left + right) >> 1;
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return current;
}