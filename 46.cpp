#include "regular_headers.hpp"

using namespace std;

vector<pair<int, bool>> vec;

void recursive(vector<vector<int>> &ans, vector<int> &temp) {

}

vector<vector<int>> permute(vector<int> &nums) {
    vec.reserve(nums.size());
    for (auto &i : nums) {
        vec.emplace_back(i, true);
    }
    // sort(vec.begin(), vec.end());
    vector<int> temp;
    vector<vector<int>> ans;
}