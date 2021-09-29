#include "regular_headers.hpp"

using namespace std;

class Solution {
private:
    vector<int> origin;
    vector<int> current;

public:
    Solution(vector<int> &nums) {
        origin = nums;
        current = nums;
        sort(current.begin(), current.end());
    }

    vector<int> reset() { return origin; }

    vector<int> shuffle() {}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */