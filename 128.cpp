#include "regular_headers.hpp"

using namespace std;

int longestConsecutive(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_map<int, bool> map;
    for (auto &i : nums) {
        map[i] = true;
    }
    int ans = 1;
    for (auto &i : map) {
        auto pos = map.find(i.first - 1);
        if (pos != map.end()) {
            continue;
        }
        int current = 1;
        for (int j = i.first + 1;;) {
            auto temp = map.find(j);
            if (temp != map.end()) {
                ++current;
                ++j;
            } else {
                ans = max(current, ans);
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
}