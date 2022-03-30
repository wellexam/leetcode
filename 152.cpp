#include "regular_headers.hpp"

int maxProduct(vector<int> &nums) {
    vector<int> maxv(nums);
    vector<int> minv(nums);
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxv[i] = max(nums[i] * maxv[i - 1], max(nums[i], nums[i] * minv[i - 1]));
        minv[i] = min(nums[i] * maxv[i - 1], min(nums[i], nums[i] * minv[i - 1]));
        ans = max(ans, maxv[i]);
    }
    return ans;
}

int main() {
    vector<int> nums{2, -5, -2, -4, 3};
    cout << maxProduct(nums);
}

// int maxProduct(vector<int> &nums) {
//     int positive_min = 1, negative_max = 1, positive_max = 1;
//     int product = 1;
//     int ans = nums[0];
//     for (int i = 0; i < nums.size(); i++) {
//         product *= nums[i];
//         if (product > 0) {
//             ans = max(ans, product / positive_min);
//         } else if (product < 0) {
//             if (negative_max >= 0) {
//                 ans = max(ans, product / positive_max);
//             } else {
//                 ans = max(ans, product / negative_max);
//             }
//         } else {
//             ans = max(ans, product);
//             product = 1;
//             positive_min = 1, negative_max = 1, positive_max = 1;
//             continue;
//         }
//         positive_max = max(product, positive_max);
//         positive_min = min(positive_min, max(1, product));
//         if (product < 0) {
//             if (negative_max > 0) {
//                 negative_max = product;
//             } else {
//                 negative_max = max(negative_max, product);
//             }
//         }
//     }
//     return ans;
// }