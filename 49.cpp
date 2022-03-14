#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, list<int>> umap;
    for (int i = 0; i < strs.size(); i++) {
        auto temp = strs[i];
        sort(temp.begin(), temp.end());
        umap[temp].push_back(i);
    }
    vector<vector<string>> ans;
    ans.reserve(umap.size());
    for (auto &i : umap) {
        vector<string> temp;
        for (auto j : i.second) {
            temp.push_back(strs[j]);
        }
        ans.push_back(move(temp));
    }
    return ans;
}