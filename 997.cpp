#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findJudge(int n, vector<vector<int>> &trust) {
    vector<bool> temp(n, false);
    vector<vector<bool>> graph(n, temp);
    for (auto &i : trust) {
        graph[i[1] - 1][i[0] - 1] = true;
    }
    vector<int> ans;
    for (auto i = 0; i < n; ++i) {
        auto is_judge = true;
        for (auto j = 0; j < n; ++j) {
            if (graph[i][j] == false && j != i) {
                is_judge = false;
                break;
            }
            if (graph[j][i]) {
                is_judge = false;
                break;
            }
        }
            if (is_judge) {
                ans.push_back(i + 1);
            }
    }
    if (ans.size() != 1) {
        return -1;
    } else {
        return ans[0];
    }
}