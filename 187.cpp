#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() < 10) {
        return vector<string>{};
    }
    vector<string> ans;
    unsigned int state = 0;
    unsigned int mask = 0b00000000000011111111111111111111;
    unordered_map<unsigned int, int> umap;
    int end = 9;
    for (int i = 0; i < end; i++) {
        state <<= 2;
        if (s[i] == 'A') {
            state += 0;
        } else if (s[i] == 'C') {
            state += 1;
        } else if (s[i] == 'G') {
            state += 2;
        } else {
            state += 3;
        }
    }
    while (end < s.size()) {
        state <<= 2;
        if (s[end] == 'A') {
            state += 0;
        } else if (s[end] == 'C') {
            state += 1;
        } else if (s[end] == 'G') {
            state += 2;
        } else {
            state += 3;
        }
        state &= mask;
        umap[state]++;
        end++;
    }
    mask = 3;
    for (auto &i : umap) {
        auto str = i.first;
        if (i.second == 1) {
            continue;
        }
        string temp(10, '\0');
        for (int j = 9; j >= 0; j--) {
            auto c = mask & str;
            if (c == 0) {
                temp[j] = 'A';
            } else if (c == 1) {
                temp[j] = 'C';
            } else if (c == 2) {
                temp[j] = 'G';
            } else {
                temp[j] = 'T';
            }
            str >>= 2;
        }
        ans.push_back(move(temp));
    }
    return ans;
}

int main() {
    string s{"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"};
    findRepeatedDnaSequences(s);
}