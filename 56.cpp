#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    bool mark[10000] = {false};
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size() - 1; ++i) {
        if (!mark[i]) {
            int a = intervals[i][0], b = intervals[i][1];
            for (int j = i + 1; j < intervals.size(); ++j) {
                if (!mark[j]) {
                    if (intervals[j][0] <= b && intervals[j][1] >= a) {
                        a = min(a, intervals[j][0]);
                        b = max(b, intervals[j][1]);
                        mark[j] = true;
                    }
                }
            }
            mark[i] = true;
            ans.push_back({a, b});
        }
    }
    if (!mark[intervals.size() - 1])
        ans.push_back({intervals[intervals.size() - 1][0], intervals[intervals.size() - 1][1]});
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{2, 3},
                                     {4, 5},
                                     {6, 7},
                                     {8, 9},
                                     {1, 10}};
    auto ans = merge(intervals);
    for (auto i : ans) {
        cout << "[" << i[0] << "," << i[1] << "]";
    }
    return 0;
}