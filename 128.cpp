#include "regular_headers.hpp"

using namespace std;

int longestConsecutive(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    map<int, bool> map;
    for (auto &i : nums) {
        map[i] = true;
    }
    sort(nums.begin(), nums.end());
    vector<int> shit;
    shit.push_back(nums.front());
    for (auto &i : nums) {
        shit.push_back(i);
    }
    int ans = 0, current = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - 1 == nums[i - 1]) {
            ++current;
        } else {
            ans = max(ans, current);
            current = 1;
        }
    }
    ans = max(ans, current);
    return ans;
}

int main() {
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
}