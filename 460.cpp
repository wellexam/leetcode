#include <utility>

#include "regular_headers.hpp"

using namespace std;

class LFUCache {
    class weight {
    public:
        int count = 0;
        list<int> que;

        weight(int _count, int key) : count(_count), que({key}) {}
    };

    class position {
    public:
        int value = 0;
        list<weight>::iterator iter_1;
        list<int>::iterator iter_2;

        position() = default;
        position(int _value, list<weight>::iterator _iter_1, list<int>::iterator _iter_2) : value(_value), iter_1(_iter_1), iter_2(_iter_2) {}
    };

    unordered_map<int, position> cache_map;
    list<weight> frequency;
    int cap;

    void func(int key, int value) {
        frequency.emplace_back(1, key);
        auto iter_1 = --frequency.end();
        auto iter_2 = iter_1->que.begin();
        cache_map[key] = position(value, iter_1, iter_2);
    }

    void put_impl(int key, int value) {
        if (frequency.empty()) {
            func(key, value);
        } else {
            if (frequency.back().count == 1) {
                frequency.back().que.push_front(key);
                cache_map[key] = position(value, --frequency.end(), frequency.back().que.begin());
            } else {
                func(key, value);
            }
        }
    }

    void move_key(int key) {
        auto &ref = cache_map[key];
        auto iter_1 = ref.iter_1;
        auto iter_2 = ref.iter_2;
        if (iter_1->count == frequency.begin()->count) {
            frequency.emplace_front(iter_1->count + 1, key);
            iter_1->que.erase(iter_2);
            if (iter_1->que.empty()) {
                frequency.erase(iter_1);
            }
            ref.iter_1 = frequency.begin();
            ref.iter_2 = ref.iter_1->que.begin();
        } else {
            auto prev_iter = iter_1;
            --prev_iter;
            if (prev_iter->count == iter_1->count + 1) {
                prev_iter->que.push_front(key);
                iter_1->que.erase(iter_2);
                if (iter_1->que.empty()) {
                    frequency.erase(iter_1);
                }
                ref.iter_1 = prev_iter;
                ref.iter_2 = prev_iter->que.begin();
            } else {
                ref.iter_1 = frequency.emplace(iter_1, iter_1->count + 1, key);
                ref.iter_2 = ref.iter_1->que.begin();
                iter_1->que.erase(iter_2);
                if (iter_1->que.empty()) {
                    frequency.erase(iter_1);
                }
            }
        }
    }

public:
    LFUCache(int capacity) : cap(capacity) { cache_map.reserve(cap); }

    int get(int key) {
        auto res = cache_map.find(key);
        if (res != cache_map.end()) {
            move_key(key);
            return cache_map[key].value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        auto res = cache_map.find(key);
        if (res == cache_map.end()) {
            if (cache_map.size() != cap) {
                put_impl(key, value);
            } else {
                auto to_delete = frequency.back().que.back();
                cache_map.erase(to_delete);
                frequency.back().que.pop_back();
                if (frequency.back().que.empty()) {
                    frequency.pop_back();
                }
                put_impl(key, value);
            }
        } else {
            cache_map[key].value = value;
            move_key(key);
        }
    }
};

void test_func(vector<int> &param, LFUCache &s) {
    if (param.size() == 1) {
        auto sb = s.get(param[0]);
        cout << sb << " ";
        if (sb == 18) {
            sb = 0;
        }
    } else {
        if (param[1] == 23) {
            param[1] = 23;
        }
        s.put(param[0], param[1]);
        cout << "null ";
    }
}

int main() {
    vector<int> ans;
    LFUCache s(10);
    vector<vector<int>> test{{10, 13}, {3, 17}, {6, 11}, {10, 5},  {9, 10}, {13},     {2, 19}, {2},     {3},      {5, 25},  {8},      {9, 22},  {5, 5},   {1, 30}, {11},     {9, 12},
                             {7},      {5},     {8},     {9},      {4, 30}, {9, 3},   {9},     {10},    {10},     {6, 14},  {3, 1},   {3},      {10, 11}, {8},     {2, 14},  {1},
                             {5},      {4},     {11, 4}, {12, 24}, {5, 18}, {13},     {7, 23}, {8},     {12},     {3, 27},  {2, 12},  {5},      {2, 9},   {13, 4}, {8, 18},  {1, 7},
                             {6},      {9, 29}, {8, 21}, {5},      {6, 30}, {1, 12},  {10},    {4, 15}, {7, 22},  {11, 26}, {8, 17},  {9, 29},  {5},      {3, 4},  {11, 30}, {12},
                             {4, 29},  {3},     {9},     {6},      {3, 4},  {1},      {10},    {3, 29}, {10, 28}, {1, 20},  {11, 13}, {3},      {3, 12},  {3, 8},  {10, 9},  {3, 26},
                             {8},      {7},     {5},     {13, 17}, {2, 27}, {11, 15}, {12},    {9, 19}, {2, 15},  {3, 16},  {1},      {12, 17}, {9, 1},   {6, 19}, {4},      {5},
                             {5},      {8, 1},  {11, 7}, {5, 2},   {9, 28}, {1},      {2, 2},  {7, 4},  {4, 22},  {7, 24},  {9, 26},  {13, 28}, {11, 26}};
    for (auto &i : test) {
        test_func(i, s);
    }
}