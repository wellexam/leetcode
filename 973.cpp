#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<pair<float, int>> heap;
    heap.reserve(k);
    int count = 0;
    while (count < k) {
        int a = points[count][0], b = points[count][1];
        float temp = sqrt(a * a + b * b);
        heap.emplace_back(temp, count);
        for (int i = heap.size() - 1; i > 0; --i) {
            if (heap[i].first > heap[(i - 1) / 2].first) {
                swap(heap[i], heap[(i - 1) / 2]);
            }
        }
        ++count;
    }
    int size = points.size();
    while (count < size) {
        int a = points[count][0], b = points[count][1];
        float temp = sqrt(a * a + b * b);
        if (temp < heap[0].first) {
            heap[0] = {temp, count};
            for (int i = k - 1; i > 0; --i) {
                if (heap[i].first > heap[(i - 1) / 2].first) {
                    swap(heap[i], heap[(i - 1) / 2]);
                }
            }
        }
        ++count;
    }
    vector<vector<int>> ans;
    ans.reserve(heap.size());
    for (auto &i : heap) {
        ans.emplace_back(points[i.second]);
    }
    return ans;
}