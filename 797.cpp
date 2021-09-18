#include "regular_headers.hpp"

using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
    path.emplace_back(node);
    if (node == graph.size() - 1) {
        ans.emplace_back(path);
        path.pop_back();
        return;
    }
    for (auto &i : graph[node]) {
        dfs(i, graph, path, ans);
    }
    path.pop_back();
    return;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ans;
    if (graph[0].empty()) {
        return ans;
    }
    vector<int> path;
    path.emplace_back(0);
    for (auto &i : graph[0]) {
        dfs(i, graph, path, ans);
    }
    return ans;
}