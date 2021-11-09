#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int total_length = nums1.size() + nums2.size();
    auto end_pos = total_length / 2 + 1;
    vector<int> ans;
    ans.reserve(end_pos);
    auto pos_1 = 0, pos_2 = 0;
    auto count = 0;
    while (count <= end_pos) {
        if (pos_1 < nums1.size() && pos_2 < nums2.size()) {
            if (nums1[pos_1] <= nums2[pos_2]) {
                ans.emplace_back(nums1[pos_1]);
                ++pos_1;
            } else {
                ans.emplace_back(nums2[pos_2]);
                ++pos_2;
            }
            ++count;
        } else if (pos_1 < nums1.size()) {
            if (total_length % 2 != 0) {
                auto mid_pos = end_pos;
                if (mid_pos > count) {
                    return nums1[mid_pos - nums2.size() - 1];
                } else {
                    return ans[mid_pos - 1];
                }
            } else {
                int a, b;
                auto mid_pos = end_pos - 1;
                if (mid_pos > count) {
                    a = nums1[mid_pos - nums2.size() - 1];
                } else {
                    a = ans[mid_pos - 1];
                }
                if (end_pos > count) {
                    b = nums1[end_pos - nums2.size() - 1];
                } else {
                    b = ans[end_pos - 1];
                }
                return (a + b) / 2.0;
            }
        } else {
            if (total_length % 2 != 0) {
                auto mid_pos = end_pos;
                if (mid_pos > count) {
                    return nums2[mid_pos - nums1.size() - 1];
                } else {
                    return ans[mid_pos - 1];
                }
            } else {
                int a, b;
                auto mid_pos = end_pos - 1;
                if (mid_pos > count) {
                    a = nums2[mid_pos - nums1.size() - 1];
                } else {
                    a = ans[mid_pos - 1];
                }
                if (end_pos > count) {
                    b = nums2[end_pos - nums1.size() - 1];
                } else {
                    b = ans[end_pos - 1];
                }
                return (a + b) / 2.0;
            }
        }
    }
    if (total_length % 2 != 0) {
        auto mid_pos = end_pos;
        return ans[mid_pos - 1];
    } else {
        int a, b;
        auto mid_pos = end_pos - 1;
        a = ans[mid_pos - 1];
        b = ans[end_pos - 1];
        return (a + b) / 2.0;
    }
}