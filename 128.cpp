#include "regular_headers.hpp"

using namespace std;

unordered_map<int, int> umap;

int find(int x) {
    if (umap[x] == x) {
        return x;
    } else {
        return umap[x] = find(umap[x]);
    }
}

int longestConsecutive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        umap[nums[i]] = nums[i];
    }
    for (auto &num : umap) {
        if (umap.count(num.second - 1)) {
            num.second--;
        }
    }
    int ans = 0;
    for (auto &num : umap) {
        ans = max(num.first - find(num.second) + 1, ans);
    }
    return ans;
}

int main() {
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
}