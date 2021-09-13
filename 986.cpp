#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
    if (secondList.empty() || firstList.empty()) {
        return {};
    }
    vector<vector<int>> ans;
    int size_a = firstList.size(), size_b = secondList.size();
    int max_num = max(firstList[size_a - 1][1], secondList[size_b - 1][1]);
    firstList.push_back({max_num + 1, max_num + 2});
    int f = 0, s = 0;
    while (f <= size_a && s < size_b) {
        if (secondList[s][1] >= firstList[f][0]) {
            if (secondList[s][0] <= firstList[f][1]) {
                ans.push_back({max(firstList[f][0], secondList[s][0]), min(firstList[f][1], secondList[s][1])});
                ++f;
                continue;
            } else {
                ++f;
                continue;
            }
        } else {
            if (f != 0) {
                --f;
            }
            ++s;
            continue;
        }
    }
    return ans;
}