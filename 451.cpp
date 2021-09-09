#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> map;
    for (auto &i : s) {
        ++map[i];
    }
    vector<pair<int, char>> vec;
    vec.reserve(map.size());
    for (auto &i : map) {
        vec.emplace_back(i.second, i.first);
    }
    sort(vec.begin(), vec.end());
    auto begin = vec.cbegin();
    auto iter = vec.cend() - 1;
    string str;
    str.reserve(s.size());
    while (iter >= begin) {
        for (int i = 0; i < iter->first; ++i) {
            str.push_back(iter->second);
        }
        --iter;
    }
    return str;
}