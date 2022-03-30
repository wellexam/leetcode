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
        auto iter = pos->second;
        int ret = iter.iter_2->value;
        if (iter.iter_1 == frequency.begin()) {
            frequency.push_front({});
            frequency.front().splice(frequency.front().end(), *iter.iter_1, iter.iter_2);
            iter.iter_1--;
            iter.iter_2->freq++;
        } else {
            auto ahead_iter = iter.iter_1;
            ahead_iter--;
            if (ahead_iter->begin()->freq == iter.iter_2->freq + 1) {
                ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                iter.iter_1--;
                iter.iter_2->freq++;
            } else {
                frequency.insert(iter.iter_1, {});
                ahead_iter = iter.iter_1;
                ahead_iter--;
                ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                iter.iter_1--;
                iter.iter_2->freq++;
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
            auto iter = pos->second;
            if (iter.iter_1 == frequency.begin()) {
                frequency.push_front({});
                frequency.front().splice(frequency.front().end(), *iter.iter_1, iter.iter_2);
                iter.iter_1--;
                iter.iter_2->freq++;
            } else {
                auto ahead_iter = iter.iter_1;
                ahead_iter--;
                if (ahead_iter->begin()->freq == iter.iter_2->freq + 1) {
                    ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                    iter.iter_1--;
                    iter.iter_2->freq++;
                } else {
                    frequency.insert(iter.iter_1, {});
                    ahead_iter = iter.iter_1;
                    ahead_iter--;
                    ahead_iter->splice(ahead_iter->end(), *iter.iter_1, iter.iter_2);
                    iter.iter_1--;
                    iter.iter_2->freq++;
                }
            }
            return;
        }
        if (hash.size() == cap) {
            auto tail = frequency.back();
            hash.erase(tail.front().key);
            tail.pop_front();
            if (tail.empty()) {
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
        if (param[1] == 23) {
            param[1] = 23;
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
    vector<vector<int>> test{{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {3}, {4, 4}, {1}, {3}, {4}};
    for (auto &i : test) {
        test_func(i, s);
    }
}