#include "regular_headers.hpp"

using namespace std;

int trap(vector<int> &height) {
    int highest = height[0], index = 0;
    for (int i = 0; i < height.size(); i++) {
        if (height[i] > highest) {
            highest = height[i];
            index = i;
        }
    }
    int current_high = height[0];
    int current_high_index = 0;
    int current_size = 0;
    int ans = 0;
    for (int i = 1; i <= index; i++) {
        if (height[i] >= current_high) {
            ans += current_high * (i - current_high_index - 1) - current_size;
            current_high = height[i];
            current_high_index = i;
            current_size = 0;
        } else {
            current_size += height[i];
        }
    }
    current_high = height.back();
    current_high_index = height.size() - 1;
    current_size = 0;
    for (int i = height.size() - 2; i >= index; i--) {
        if (height[i] >= current_high) {
            ans += current_high * (current_high_index - i - 1) - current_size;
            current_high = height[i];
            current_high_index = i;
            current_size = 0;
        } else {
            current_size += height[i];
        }
    }
    return ans;
}

int main() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
    return 0;
}