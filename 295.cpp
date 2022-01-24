#include "regular_headers.hpp"

using namespace std;

class MedianFinder {
    vector<int> s_heap;
    vector<int> l_heap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (s_heap.size() == 0) {
            s_heap.push_back(num);
        } else {
            if (num > s_heap.front()) {
                l_heap.push_back(num);
                auto l_cursor = l_heap.size() - 1;
                while (l_cursor > 0 && l_heap[l_cursor] < l_heap[(l_cursor - 1) / 2]) {
                    swap(l_heap[l_cursor], l_heap[(l_cursor - 1) / 2]);
                    l_cursor = (l_cursor - 1) / 2;
                }
            } else {
                s_heap.push_back(num);
                auto s_cursor = s_heap.size() - 1;
                while (s_cursor > 0 && s_heap[s_cursor] > s_heap[(s_cursor - 1) / 2]) {
                    swap(s_heap[s_cursor], s_heap[(s_cursor - 1) / 2]);
                    s_cursor = (s_cursor - 1) / 2;
                }
            }
            if (s_heap.size() == l_heap.size() - 1) {
                auto top = l_heap.front();
                swap(l_heap.front(), l_heap.back());
                l_heap.pop_back();
                auto l_cursor = 0;
                while ((l_cursor + 1) * 2 - 1 < l_heap.size()) {
                    if (l_heap[l_cursor] > l_heap[(l_cursor + 1) * 2 - 1]) {
                        if ((l_cursor + 1) * 2 < l_heap.size() && l_heap[l_cursor] > l_heap[(l_cursor + 1) * 2]) {
                            if (l_heap[(l_cursor + 1) * 2 - 1] < l_heap[(l_cursor + 1) * 2]) {
                                swap(l_heap[(l_cursor + 1) * 2 - 1], l_heap[l_cursor]);
                                l_cursor = (l_cursor + 1) * 2 - 1;
                            } else {
                                swap(l_heap[(l_cursor + 1) * 2], l_heap[l_cursor]);
                                l_cursor = (l_cursor + 1) * 2;
                            }
                        } else {
                            swap(l_heap[(l_cursor + 1) * 2 - 1], l_heap[l_cursor]);
                            l_cursor = (l_cursor + 1) * 2 - 1;
                        }
                    } else if ((l_cursor + 1) * 2 < l_heap.size() && l_heap[l_cursor] > l_heap[(l_cursor + 1) * 2]) {
                        swap(l_heap[(l_cursor + 1) * 2], l_heap[l_cursor]);
                        l_cursor = (l_cursor + 1) * 2;
                    } else {
                        break;
                    }
                }
                s_heap.push_back(top);
                auto s_cursor = s_heap.size() - 1;
                while (s_cursor > 0 && s_heap[s_cursor] > s_heap[(s_cursor - 1) / 2]) {
                    swap(s_heap[s_cursor], s_heap[(s_cursor - 1) / 2]);
                    s_cursor = (s_cursor - 1) / 2;
                }
            } else if (s_heap.size() == l_heap.size() + 2) {
                auto top = s_heap.front();
                swap(s_heap.front(), s_heap.back());
                s_heap.pop_back();
                auto s_cursor = 0;
                while ((s_cursor + 1) * 2 - 1 < s_heap.size()) {
                    if (s_heap[s_cursor] < s_heap[(s_cursor + 1) * 2 - 1]) {
                        if ((s_cursor + 1) * 2 < s_heap.size() && s_heap[s_cursor] < s_heap[(s_cursor + 1) * 2]) {
                            if (s_heap[(s_cursor + 1) * 2 - 1] > s_heap[(s_cursor + 1) * 2]) {
                                swap(s_heap[(s_cursor + 1) * 2 - 1], s_heap[s_cursor]);
                                s_cursor = (s_cursor + 1) * 2 - 1;
                            } else {
                                swap(s_heap[(s_cursor + 1) * 2], s_heap[s_cursor]);
                                s_cursor = (s_cursor + 1) * 2;
                            }
                        } else {
                            swap(s_heap[(s_cursor + 1) * 2 - 1], s_heap[s_cursor]);
                            s_cursor = (s_cursor + 1) * 2 - 1;
                        }
                    } else if ((s_cursor + 1) * 2 < s_heap.size() && s_heap[s_cursor] < s_heap[(s_cursor + 1) * 2]) {
                        swap(s_heap[(s_cursor + 1) * 2], s_heap[s_cursor]);
                        s_cursor = (s_cursor + 1) * 2;
                    } else {
                        break;
                    }
                }
                l_heap.push_back(top);
                auto l_cursor = l_heap.size() - 1;
                while (l_cursor > 0 && l_heap[l_cursor] < l_heap[(l_cursor - 1) / 2]) {
                    swap(l_heap[l_cursor], l_heap[(l_cursor - 1) / 2]);
                    l_cursor = (l_cursor - 1) / 2;
                }
            }
        }
    }

    double findMedian() {
        if (s_heap.empty()) {
            return 0;
        }
        if (s_heap.size() == l_heap.size()) {
            return (s_heap.front() + l_heap.front()) / 2.0;
        } else {
            return s_heap.front();
        }
    }
};

int main() {
    MedianFinder m;
    vector<vector<int>> input{{}, {6}, {}, {10}, {}, {2}, {}, {6}, {}, {5}, {}, {0}, {}, {6}, {}, {3}, {}, {1}, {}, {0}, {}, {0}, {}};
    for (auto &i : input) {
        if (i.empty()) {
            continue;
        }
        auto num = i[0];
        m.addNum(num);
        cout << m.findMedian();
        cout << ' ';
    }
    return 0;
}