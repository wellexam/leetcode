#pragma once
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class priority_que {
private:
    vector<pair<int, int>> que;
    int row = 1;

public:
    priority_que();

    int top();

    void pop();

    void pop_with(const pair<int, int> &);

    void insert(const pair<int, int> &);
};

void priority_que::insert(const pair<int, int> &item) {
    int size = que.size();
    int count = 1;
    row = 1;
    while (count < size) {
        ++row;
        count = count * 2 - 1;
    }
    que.emplace_back(item);
    // for (int i = size; i > 0; --i) {
    //     if (que[i].first > que[(i - 1) / 2].first) {
    //         swap(que[i].first, que[(i - 1) / 2].first);
    //     }
    // }
    int num_of_second_last_line = ;
    for (int i = size; i > count; --i) {

    }
}