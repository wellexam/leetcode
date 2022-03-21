#include "regular_headers.hpp"

using namespace std;

int longestConsecutive(vector<int> &nums) {
    unordered_set<int> uset;
    for (auto i : nums) {
        uset.insert(i);
    }
    int ans = 0;
    for (auto &num : uset) {
        auto count = 0;
        if (!uset.count(num - 1)) {
            auto current = num;
            while (uset.count(current)) {
                count++;
                current++;
            }
            ans = max(count, ans);
        }
    }
    return ans;
}

int main() {
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
}