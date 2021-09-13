#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1, max = 0;
    while (left < right) {
        max = std::max((right - left) * min(height[left], height[right]), max);
        if (height[left] <= height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return max;
}