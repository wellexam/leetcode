#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (int i = 0; i < 26; ++i)
        map[char(i + 'a')] = 0;
    for (int i = 0; i < 26; ++i)
        map[char(i + 'A')] = 0;
    for (auto i : s)
        ++map[i];
    int count = 0;
    bool flag = false;
    for (auto i : map) {
        if ((i.second % 2) != 0) {
            count += i.second - 1;
            flag = true;
        } else
            count += i.second;
    }
    if (flag)
        ++count;
    return count;
}