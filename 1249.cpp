#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string minRemoveToMakeValid(string s) {
    int count = 0;
    int last = 0;
    vector<bool> shit(s.size(), true);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
            last = i;
        } else if (s[i] == ')') {
            if (count) {
                count--;
            } else {
                shit[i] = false;
            }
        }
    }
    int i = last;
    while (count--) {
        for (; i >= 0; i--) {
            if (s[i] == '(') {
                shit[i] = false;
                i--;
                break;
            }
        }
    }
    string ans;
    for (i = 0; i < s.size(); i++) {
        if (shit[i]) {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main() {
    string s{"))(("};
    cout << minRemoveToMakeValid(s);
}