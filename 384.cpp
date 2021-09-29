#include "regular_headers.hpp"

using namespace std;

class Solution {
private:
    vector<int> origin;

public:
    Solution(vector<int> &nums) { origin = nums; }

    vector<int> reset() { return origin; }

    vector<int> shuffle() {
        int len = origin.size();
        vector<bool> table(len, false);
        vector<int> ans(len, 0);
        for (auto &i : origin) {
            auto index = rand() % len;
            while (table[index]) {
                index = rand() % len;
            }
            table[index] = true;
            ans[index] = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */