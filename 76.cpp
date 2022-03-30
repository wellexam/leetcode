#include "regular_headers.hpp"

using namespace std;

string minWindow(string s, string t) {
    int min = s.size() + 1, begin = 0, end = -1;
    unordered_map<char, int> t_table;
    for (auto c : t) {
        t_table[c]++;
    }
    unordered_map<char, int> window;
    auto cmp = [&t_table, &window]() -> bool {
        auto ch = 'a';
        while (ch <= 'z') {
            if (window[ch] < t_table[ch]) {
                return false;
            }
            ch++;
        }
        ch = 'A';
        while (ch <= 'Z') {
            if (window[ch] < t_table[ch]) {
                return false;
            }
            ch++;
        }
        return true;
    };
    int left = 0, right = 0;
    window[s[right]]++;
    while (left <= right) {
        if (cmp()) {
            if (min > right - left + 1) {
                min = right - left + 1;
                begin = left;
                end = right;
            }
            window[s[left]]--;
            left++;
        } else {
            right++;
            if (right <= s.size() - 1) {
                window[s[right]]++;
            } else {
                break;
            }
        }
    }
    string ans;
    ans.append(s.begin() + begin, s.begin() + end + 1);
    return ans;
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
}