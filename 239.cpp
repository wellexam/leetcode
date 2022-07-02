#include "regular_headers.hpp"

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int current = 1;
    deque<int> que;
    vector<int> ans;
    ans.reserve(nums.size() - k + 1);
    que.push_back(0);
    while (current < k) {
        while (!que.empty() && nums[current] > nums[que.back()]) {
            que.pop_back();
        }
        que.push_back(current);
        while (!que.empty() && que.front() <= current - k) {
            que.pop_front();
        }
        current++;
    }
    ans.push_back(nums[que.front()]);
    while (current < nums.size()) {
        while (!que.empty() && nums[current] > nums[que.back()]) {
            que.pop_back();
        }
        que.push_back(current);
        while (!que.empty() && que.front() <= current - k) {
            que.pop_front();
        }
        ans.push_back(nums[que.front()]);
        current++;
    }
    return ans;
}

int main() {
    vector<int> nums{9, 10, 9, -7, -4, -8, 2, -6};
    auto res = maxSlidingWindow(nums, 5);
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}