#include "regular_headers.hpp"

using namespace std;

int minDistance(string word1, string word2) {
    int size_1 = word1.size(), size_2 = word2.size();
    if (size_1 == 0) {
        return size_2;
    }
    if (size_2 == 0) {
        return size_1;
    }
    vector<int> temp(size_2, -1);
    vector<vector<int>> dp(size_1, temp);
    if (word1[0] == word2[0]) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for (int i = 0; i < size_1; ++i) {
        auto char1 = word1[i];
        for (int j = 0; j < size_2; ++j) {
            auto char2 = word2[j];
            if (char1 == char2) {
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 1;
                }
            } else {
                auto a = 0, b = 0;
                if (i > 0) {
                    a = dp[i - 1][j];
                }
                if (j > 0) {
                    b = dp[i][j - 1];
                }
                dp[i][j] = max(a, b);
            }
        }
    }
    stack<pair<int, int>> serial;
    int index_1 = size_1 - 1, index_2 = size_2 - 1;
    while (index_1 >= 0 && index_2 >= 0) {
        auto temp = dp[index_1][index_2];
        if (index_1 > 0 && index_2 > 0 && temp > dp[index_1 - 1][index_2 - 1]) {
            serial.emplace(index_1, index_2);
            --index_1;
            --index_2;
        } else if (index_1 > 0) {
            --index_1;
        } else if (index_2 > 0) {
            --index_2;
        } else if (word1[index_1] == word2[index_2]) {
            serial.emplace(index_1, index_2);
            break;
        }
    }
    // if (word1[index_1] == word2[index_2]) {
    //     serial.emplace(index_1, index_2);
    // }
    auto ans = 0;
    pair<int, int> prev(-1, -1);
    if (!serial.empty()) {
        prev = serial.top();
        serial.pop();
        ans += max(prev.first, prev.second);
    }
    while (!serial.empty()) {
        auto current = serial.top();
        serial.pop();
        ans += max(current.first - prev.first - 1, current.second - current.second - 1);
        prev = current;
    }
    ans += max(size_1 - 1 - prev.first, size_2 - 1 - prev.second);
    return ans;
}

int main() {
    string word1 = "ahijklmn", word2 = "oabcdefg";
    cout << minDistance(word1, word2);
    return 0;
}