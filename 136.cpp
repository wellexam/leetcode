#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;
    sort(nums.begin(), nums.end());
    const int max = *(nums.end() - 1);
    vector<int>::iterator mark;
    int a, b, c;
    a = *nums.begin() - 1;
    for (auto iter_1 = nums.begin(); iter_1 != (nums.end() - 2) && *iter_1 <= 0; ++iter_1) {
        if (*iter_1 == a)
            continue;
        a = *iter_1;
        b = a - 1;
        mark = nums.end() - 1;
        for (auto iter_2 = iter_1 + 1; iter_2 < mark; ++iter_2) {
            if (*iter_2 == b)
                continue;
            b = *iter_2;
            if (a + b + max < 0)
                continue;
            auto iter_3 = mark;
            for (; iter_3 > iter_2; --iter_3) {
                c = *iter_3;
                int sum = a + b + c;
                if (sum == 0) {
                    ans.push_back({a, b, c});
                    mark = iter_3;
                    break;
                } else if (sum < 0)
                    break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> n = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    auto ans = threeSum(n);
    if (ans.empty())
        return 0;
    for (const auto &i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}