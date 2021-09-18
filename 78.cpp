#include "regular_headers.hpp"

using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    unsigned int count = 0;
    vector<vector<int>> ans;
    int max = ~(1 << 31);
    auto n = nums.size();
    max = max >> (32 - n - 1);
    while (count <= max) {
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if ((count >> i) & 1) {
                temp.emplace_back(nums[i]);
            }
        }
        ans.emplace_back(temp);
        ++count;
    }
    return ans;
}