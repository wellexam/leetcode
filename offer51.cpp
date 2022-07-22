#include "regular_headers.hpp"

vector<int> a, d;

void buildTree(int s, int t, int p) {
    if (s == t) {
        d[p] = a[s];
        return;
    }
    int m = s + ((t - s) >> 1);
    buildTree(s, m, p * 2 + 1);
    buildTree(m + 1, t, p * 2 + 2);
    d[p] = max(d[2 * p + 1], d[2 * p + 2]);
}

int search(int l, int r, int s, int t, int p, int target) {
    if (l <= s && t <= r) {
        if (s == t) {
            if (d[p] < target) {
                return 1;
            } else {
                return 0;
            }
        }
        if (d[p] < target) {
            return t - s + 1;
        }
        int m = s + ((t - s) >> 1);
        return search(l, r, s, m, p * 2 + 1, target) + search(l, r, m + 1, t, p * 2 + 2, target);
    } else {
        if (s == t || t < l || s > r) {
            return 0;
        }
        int m = s + ((t - s) >> 1);
        return search(l, r, s, m, p * 2 + 1, target) + search(l, r, m + 1, t, p * 2 + 2, target);
    }
}

int reversePairs(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    a.swap(nums);
    d = vector<int>(a.size() * 4, 0);
    buildTree(0, a.size() - 1, 0);
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        ans += search(i, a.size() - 1, 0, a.size() - 1, 0, a[i]);
    }
    return ans;
}

int main() {
    vector<int> nums{7, 5, 6, 4};
    cout << reversePairs(nums) << endl;
    return 0;
}