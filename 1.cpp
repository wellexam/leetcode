#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (auto &i : nums) {
        ++map[i];
    }
    for (auto &i : map) {
        --i.second;
        auto pos = map.find(target - i.first);
        if (pos != map.end() && pos->second != 0) {
            if (target - i.first == i.first) {
                int a = find(nums.begin(), nums.end(), i.first) - nums.begin();
                int b = find(nums.begin() + a + 1, nums.end(), i.first) - nums.begin();
                return vector<int>{a, b};
            } else {
                int a = find(nums.begin(), nums.end(), i.first) - nums.begin();
                int b = find(nums.begin(), nums.end(), target - i.first) - nums.begin();
                return vector<int>{min(a, b), max(a, b)};
            }
        }
        ++i.second;
    }
    return vector<int>{0, 1};
}

int main() {
    vector<int> shit = {3, 3};
    auto ans = twoSum(shit, 6);
    cout << ans[0] << " " << ans[1];
}