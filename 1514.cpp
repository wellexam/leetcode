#include "regular_headers.hpp"

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
    vector<vector<double>> table(n, vector<double>(n, 0));
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
        table[edges[i][1]][edges[i][0]] = table[edges[i][0]][edges[i][1]] = succProb[i];
        graph[edges[i][1]].push_back(edges[i][0]);
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    table[start][start] = 1;
    vector<bool> isVisited(n, false);
    priority_queue<pair<double, int>> que;
    que.emplace(table[start][start], start);
    while (!que.empty()) {
        if (isVisited[end]) {
            break;
        }
        auto temp = que.top();
        que.pop();
        double mind = temp.first;
        int u = temp.second;
        if (isVisited[u]) {
            continue;
        }
        isVisited[u] = true;
        for (auto j : graph[u]) {
            if (!isVisited[j] && table[start][j] <= mind * table[u][j]) {
                table[start][j] = mind * table[u][j];
                que.emplace(table[start][j], j);
            }
        }
    }
    return table[start][end];
}

int main() {
    vector<vector<int>> edges{{0, 3}, {1, 7}, {1, 2}, {0, 9}};
    vector<double> succProb{0.31, 0.9, 0.86, 0.36};
    cout << maxProbability(10, edges, succProb, 2, 3);
    return 0;
}