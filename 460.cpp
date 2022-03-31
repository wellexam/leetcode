#include "regular_headers.hpp"

using namespace std;

class LFUCache {
public:
    class key_value {
    public:
        int key;
        int value;
        int freq;
    };

    class list_iter {
    public:
        list<list<key_value>>::iterator iter_1;
        list<key_value>::iterator iter_2;
    };

    unordered_map<int, list_iter> hash;
    list<list<key_value>> frequency;
    int cap;

    LFUCache(int capacity) { cap = capacity; }

    int get(int key) {
        auto pos = hash.find(key);
        if (pos == hash.end()) {
            return -1;
        }
        auto &iter = pos->second;
        int ret = iter.iter_2->value;
        if (iter.iter_1 == frequency.begin()) {
            frequency.push_front({});
            frequency.front().splice(frequency.front().end(), *iter.iter_1, iter.iter_2);
            auto temp = iter.iter_1;
            iter.iter_1--;
            iter.iter_2->freq++;
            if (temp->empty()) {
                frequency.erase(temp);
            }
        } else {
            auto ahead_iter = iter.iter_1;
            ahead_iter--;
            if (ahead_iter->begin()->freq == iter.iter_2->freq + 1) {
                ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                auto temp = iter.iter_1;
                iter.iter_1--;
                iter.iter_2->freq++;
                if (temp->empty()) {
                    frequency.erase(temp);
                }
            } else {
                frequency.insert(iter.iter_1, {});
                ahead_iter = iter.iter_1;
                ahead_iter--;
                ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                auto temp = iter.iter_1;
                iter.iter_1--;
                iter.iter_2->freq++;
                if (temp->empty()) {
                    frequency.erase(temp);
                }
            }
        }
        return ret;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        auto pos = hash.find(key);
        if (pos != hash.end()) {
            auto &iter = pos->second;
            iter.iter_2->value = value;
            if (iter.iter_1 == frequency.begin()) {
                frequency.push_front({});
                frequency.front().splice(frequency.front().end(), *iter.iter_1, iter.iter_2);
                auto temp = iter.iter_1;
                iter.iter_1--;
                iter.iter_2->freq++;
                if (temp->empty()) {
                    frequency.erase(temp);
                }
            } else {
                auto ahead_iter = iter.iter_1;
                ahead_iter--;
                if (ahead_iter->begin()->freq == iter.iter_2->freq + 1) {
                    ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                    auto temp = iter.iter_1;
                    iter.iter_1--;
                    iter.iter_2->freq++;
                    if (temp->empty()) {
                        frequency.erase(temp);
                    }
                } else {
                    frequency.insert(iter.iter_1, {});
                    ahead_iter = iter.iter_1;
                    ahead_iter--;
                    ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                    auto temp = iter.iter_1;
                    iter.iter_1--;
                    iter.iter_2->freq++;
                    if (temp->empty()) {
                        frequency.erase(temp);
                    }
                }
            }
            return;
        }
        if (hash.size() == cap) {
            auto tail = frequency.end();
            tail--;
            hash.erase(tail->front().key);
            tail->pop_front();
            if (tail->empty()) {
                frequency.pop_back();
            }
        }
        key_value temp;
        temp.key = key;
        temp.value = value;
        temp.freq = 1;
        if (frequency.empty()) {
            frequency.push_back({temp});
        } else if (frequency.back().front().freq == 1) {
            frequency.back().push_back(temp);
        } else {
            frequency.push_back({temp});
        }
        list_iter iters;
        iters.iter_1 = frequency.end();
        iters.iter_1--;
        iters.iter_2 = iters.iter_1->end();
        iters.iter_2--;
        hash[key] = iters;
        return;
    }
};

void test_func(vector<int> &param, LFUCache &s) {
    if (param.size() == 1) {
        auto temp = param[0];
        auto sb = s.get(temp);
        cout << sb << " ";
        if (sb == 18) {
            sb = 0;
        }
    } else {
        if (param[1] == 2) {
            param[1] = 2;
        }
        auto temp1 = param[0];
        auto temp2 = param[1];
        s.put(temp1, temp2);
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