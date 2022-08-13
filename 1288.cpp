#include "regular_headers.hpp"

static bool cmp(const vector<int> &lhs, const vector<int> &rhs) {
    if (lhs[0] == rhs[0]) {
        return lhs[1] > rhs[1];
    }
    return lhs[0] < rhs[0];
}

int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<bool> isDeleted(intervals.size(), false);
    for (int i = 0; i < intervals.size(); i++) {
        for (int j = i + 1; j < intervals.size() && intervals[j][0] <= intervals[i][1]; j++) {
            if (intervals[j][1] <= intervals[i][1]) {
                isDeleted[j] = true;
            }
        }
    }
    int count = 0;
    for (auto i : isDeleted) {
        if (i) {
            count++;
        }
    }
    return intervals.size() - count;
}

int main() {
    vector<vector<int>> intervals{{1, 2}, {1, 4}, {3, 4}};
    cout << removeCoveredIntervals(intervals);
    return 0;
}