#include "regular_headers.hpp"

static bool cmp(const vector<int> &lhs, const vector<int> &rhs) {
    return lhs[1] < rhs[1];
}

int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), cmp);
    int count = 0;
    for (int i = 0; i < points.size(); i++) {
        int j;
        for (j = i + 1; j < points.size(); j++) {
            if (points[j][0] > points[i][1]) {
                break;
            }
        }
        i = j - 1;
        count++;
    }
    return count;
}

int main() {
    vector<vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points);
    return 0;
}