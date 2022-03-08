#include "regular_headers.hpp"

using namespace std;

vector<int> partitionLabels(string s) {
    vector<pair<int, int>> range(26, pair<int, int>{-1, -1});
    for (int i = 0; i < s.size(); i++) {
        if (range[s[i] - 'a'].first == -1) {
            range[s[i] - 'a'].first = i;
            range[s[i] - 'a'].second = i;
        } else {
            range[s[i] - 'a'].second = i;
        }
    }
    deque<pair<int, int>> merge;
    int start = 0, end = range[s[0] - 'a'].second;
    for (int i = 0; i < s.size(); i++) {
        if (range[s[i] - 'a'].second > end) {
            end = range[s[i] - 'a'].second;
            continue;
        }
        if (end == i) {
            merge.emplace_back(start, end);
            if (i + 1 < s.size()) {
                start = i + 1;
                end = range[s[i + 1] - 'a'].second;
            } else {
                break;
            }
        }
    }
    vector<int> ans(merge.size());
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = merge[i].second - merge[i].first + 1;
    }
    return ans;
}

int main() {
    auto ans = partitionLabels("ababcbacadefegdehijhklij");
    for (auto i : ans)
        cout << i << " ";
    return 0;
}