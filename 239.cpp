#include "regular_headers.hpp"

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<pair<int, int>> que;
    que.emplace_back(nums[0], 0);
    for (int i = 1; i < k; ++i) {
        if (nums[i] > que.front().first) {
            que.clear();
            que.emplace_back(nums[i], i);
        } else {
            while (nums[i] > que.back().first) {
                que.pop_back();
            }
            que.emplace_back(nums[i], i);
        }
    }
    vector<int> res;
    res.reserve(nums.size());
    res.push_back(que.front().first);
    for (int i = k; i < nums.size(); ++i) {
        if (que.front().second <= i - k) {
            que.pop_front();
        }
        if (nums[i] > que.front().first) {
            que.clear();
            que.emplace_back(nums[i], i);
        } else {
            while (nums[i] > que.back().first) {
                que.pop_back();
            }
            que.emplace_back(nums[i], i);
        }
        res.push_back(que.front().first);
    }
    return res;
}

int main() {
    vector<int> nums{9, 10, 9, -7, -4, -8, 2, -6};
    auto res = maxSlidingWindow(nums, 5);
    return 0;
}