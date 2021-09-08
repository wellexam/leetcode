#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k) {
    vector<int> bucket(20001, 0);
    int max = -10001;
    for (auto &i : nums) {
        ++bucket[i + 10000];
        if (i > max) {
            max = i;
        }
    }
    for (int i = 0; i < k; ++i) {
        if (bucket[max + 10000]) {
            --bucket[max + 10000];
        } else {
            for (int j = max - 1; j >= -10000; --j) {
                if (bucket[j + 10000]) {
                    max = j;
                    --bucket[j + 10000];
                    break;
                }
            }
        }
    }
    return max;
}

int main() {
    vector<int> nums{-1, 2, 0};
    cout << findKthLargest(nums, 3);
    return 0;
}