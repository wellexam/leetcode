#include "regular_headers.hpp"

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    using point = tuple<int, int, int>;
    priority_queue<point> heap;
    for (int i = 0; i < points.size(); i++) {
        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        if (heap.size() < k) {
            heap.push({dist, points[i][0], points[i][1]});
        } else {
            if (dist < get<0>(heap.top())) {
                heap.pop();
                heap.push({dist, points[i][0], points[i][1]});
            } else {
                continue;
            }
        }
    }
    vector<vector<int>> ans;
    ans.reserve(k);
    while (!heap.empty()) {
        auto temp = heap.top();
        heap.pop();
        ans.push_back({get<1>(temp), get<2>(temp)});
    }
    return ans;
}

int main() {
    vector<vector<int>> vec{{1, 3}, {-2, 2}};
    auto ans = kClosest(vec, 1);
    return 0;
}