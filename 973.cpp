#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<pair<int, int>> heap;
    heap.reserve(k);
    int count = 0;
    while (count < k - 1) {
        int a = points[count][0], b = points[count][1];
        heap.emplace_back(a * a + b * b, count);
        ++count;
    }
    if (count == k - 1) {
        int a = points[count][0], b = points[count][1];
        heap.emplace_back(a * a + b * b, count);
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
        int temp = a * a + b * b;
        if (temp < heap[0].first) {
            heap[0] = {temp, count};
            for (int row = 0; row * 2 + 2 < k;) {
                auto is_down = false;
                for (int current = 0; current < row * 2 + 1 && current < k; ++current) {
                    if (heap[row + current].first < heap[(row + current) * 2 + 1].first) {
                        swap(heap[row + current], heap[(row + current) * 2 + 1]);
                        is_down = true;
                    }
                    if (heap[row + current].first < heap[(row + current) * 2 + 2].first) {
                        swap(heap[row + current], heap[(row + current) * 2 + 2]);
                        is_down = true;
                    }
                }
                if (!is_down) {
                    break;
                }
                row = row * 2 + 1;
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

int main() {
    vector<vector<int>> vec{{89, 6}, {-39, -4}, {-13, 91}, {97, -61}, {1, 7}, {-66, 69}, {-51, 68}, {82, -6}, {-21, 44}, {-58, -83}, {-40, 73}, {-88, -24}};
    kClosest(vec, 6);
	return 0;
}