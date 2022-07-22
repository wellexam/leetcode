#include "regular_headers.hpp"

using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int left = 0, right = 0;
    unordered_map<char, bool> umap;
    char current = s[0];
    while (right < s.size()) {
        current = s[right];
        if (umap[current]) {
            ans = max(ans, right - left);
            umap[s[left]] = false;
            ++left;
        } else {
            umap[current] = true;
            ans = max(ans, right - left + 1);
            ++right;
        }
    }
    return ans;
}