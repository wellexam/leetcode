#include "regular_headers.hpp"

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    vector<int> tail(nums.size() + 1);
    int currentLen = 1;
    tail[1] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int num = nums[i];
        int left = 1, right = currentLen, mid = left + ((right - left) >> 1);
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (num > tail[mid]) {
                if (mid < currentLen) {
                    if (tail[mid + 1] > num) {
                        tail[mid + 1] = num;
                        break;
                    } else if (tail[mid + 1] < num) {
                        left = mid + 1;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    currentLen++;
                    tail[currentLen] = num;
                    break;
                }
            } else if (num < tail[mid]) {
                if (mid > 1) {
                    if (tail[mid - 1] < num) {
                        tail[mid] = num;
                        break;
                    } else if (tail[mid - 1] > num) {
                        right = mid;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    tail[mid] = num;
                    break;
                }
            } else {
                break;
            }
        }
    }
    return currentLen;
}

int main() {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    auto ans = lengthOfLIS(nums);
    cout << ans << endl;
    return 0;
}