#include "regular_headers.hpp"

using namespace std;

int trap(vector<int> &height) {
    int max_height = 0, max_pos = 0, size = height.size();
    for (int i = 0; i < size; ++i) {
        if (height[i] > max_height) {
            max_height = height[i];
            max_pos = i;
        }
    }
    int ans = 0;
    int current_max = 0, current_block = 0, current_max_pos = 0;
    for (int i = 0; i <= max_pos; ++i) {
        if (height[i] >= current_max) {
            ans += (i - current_max_pos - 1) * current_max - current_block;
            current_block = 0;
            current_max = height[i];
            current_max_pos = i;
        } else {
            current_block += height[i];
        }
    }
    current_max = 0, current_block = 0, current_max_pos = size - 1;
    for (int i = size - 1; i >= max_pos; --i) {
        if (height[i] >= current_max) {
            ans += (current_max_pos - i - 1) * current_max - current_block;
            current_block = 0;
            current_max = height[i];
            current_max_pos = i;
        } else {
            current_block += height[i];
        }
    }
    return ans;
}