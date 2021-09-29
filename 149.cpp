#include "regular_headers.hpp"

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

int maxPoints(vector<vector<int>> &points) {
    // sort(points.begin(), points.end(), cmp);
    unordered_map<string, int> map;
    int n = points.size();
    for (int i = 0; i < n - 1; ++i) {
        auto x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < n; ++j) {
            auto x2 = points[j][0], y2 = points[j][1];
            int a = x1 - x2, b = y1 - y2;
            if (!a) {
                ++map[to_string(x1) + ","];
                continue;
            }
            if (!b) {
                ++map[to_string(y1) + ","];
                continue;
            }
            double slope = b * 1.0 / a;
            double intercept = y1 - slope * x1;
            ++map[to_string(slope) + "," + to_string(intercept)];
        }
    }
    auto ans = 0;
    for (auto &i : map) {
        ans = max(i.second, ans);
    }
    return ans;
}

int main() {
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << maxPoints(points);
    return 0;
}