#include "regular_headers.hpp"

using namespace std;

void enums(unordered_map<int, int> &umap, unordered_map<int, int>::iterator iter, vector<vector<int>> &ans, vector<int> &path) {
    if (iter == umap.end()) {
        ans.push_back(path);
        return;
    }
    int count = iter->second;
    auto temp = iter;
    temp++;
    enums(umap, temp, ans, path);
    cout << iter->first << " " << iter->second << endl;
    while (iter->second > 0) {
        iter->second--;
        path.push_back(iter->first);
        enums(umap, temp, ans, path);
        cout << iter->first << " " << iter->second << endl;
    }
    cout << iter->first << " " << iter->second << endl;
    while (iter->second < count) {
        iter->second++;
        path.pop_back();
        cout << iter->first << " " << iter->second << endl;
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (auto i : nums) {
        umap[i]++;
    }
    vector<vector<int>> ans;
    vector<int> path;
    path.reserve(nums.size());
    enums(umap, umap.begin(), ans, path);
    return ans;
}

int main() {
    vector<int> nums{1, 2, 2};
    auto ans = subsetsWithDup(nums);
    return 0;
}