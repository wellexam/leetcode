#include "regular_headers.hpp"

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size(), count = 0;
    bool flag = false;
    vector<bool> temp(n, false);
    vector<vector<bool>> if_visited(n, temp);
    vector<vector<bool>> if_added(n, temp);
    if (grid[0][0] == 1) {
        return -1;
    }
    deque<pair<int, int>> que, que_next_level;
    que.emplace_back(0, 0);
    while (!que.empty()) {
        auto current = que.front();
        que.pop_front();
        int x = current.first, y = current.second;
        if (x == n - 1 && y == n - 1) {
            ++count;
            flag = true;
            // cout << x << "," << y << " ";
            break;
        }
        if (if_visited[x][y]) {
            if (que.empty()) {
                swap(que, que_next_level);
                ++count;
                // cout << count << endl;
            }
            continue;
        }
        if_visited[x][y] = true;
        if (y - 1 > 0) {
            if (x - 1 >= 0 && !grid[x - 1][y - 1] && !if_visited[x - 1][y - 1] && !if_added[x - 1][y - 1]) {
                que_next_level.emplace_back(x - 1, y - 1);
                if_added[x - 1][y - 1] = true;
            }
            if (!grid[x][y - 1] && !if_visited[x][y - 1] && !if_added[x][y - 1]) {
                que_next_level.emplace_back(x, y - 1);
                if_added[x][y - 1] = true;
            }
            if (x + 1 < n && !grid[x + 1][y - 1] && !if_visited[x + 1][y - 1] && !if_added[x + 1][y - 1]) {
                que_next_level.emplace_back(x + 1, y - 1);
                if_added[x + 1][y - 1] = true;
            }
        }
        if (y + 1 < n) {
            if (x - 1 >= 0 && !grid[x - 1][y + 1] && !if_visited[x - 1][y + 1] && !if_added[x - 1][y + 1]) {
                que_next_level.emplace_back(x - 1, y + 1);
                if_added[x - 1][y + 1] = true;
            }
            if (!grid[x][y + 1] && !if_visited[x][y + 1] && !if_added[x][y + 1]) {
                que_next_level.emplace_back(x, y + 1);
                if_added[x][y + 1] = true;
            }
            if (x + 1 < n && !grid[x + 1][y + 1] && !if_visited[x + 1][y + 1] && !if_added[x + 1][y + 1]) {
                que_next_level.emplace_back(x + 1, y + 1);
                if_added[x + 1][y + 1] = true;
            }
        }
        if (x - 1 >= 0 && !grid[x - 1][y] && !if_visited[x - 1][y] && !if_added[x - 1][y]) {
            que_next_level.emplace_back(x - 1, y);
            if_added[x - 1][y] = true;
        }
        if (x + 1 < n && !grid[x + 1][y] && !if_visited[x + 1][y] && !if_added[x + 1][y]) {
            que_next_level.emplace_back(x + 1, y);
            if_added[x + 1][y] = true;
        }
        // cout << x << "," << y << " ";
        if (que.empty()) {
            swap(que, que_next_level);
            // cout << count << endl;
            ++count;
        }
    }
    if (flag) {
        return count;
    }
    return -1;
}