#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> table;
    int prefixSum = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        auto iter = table.find(prefixSum - k);
        if (iter != table.end()) {
            ans += iter->second;
        }
        if (prefixSum == k) {
            ans++;
        }
        table[prefixSum]++;
    }
    return ans;
}

int main() {
    vector<int> nums{1, 1, 1};
    subarraySum(nums, 2);
}