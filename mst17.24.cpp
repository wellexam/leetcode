#include "regular_headers.hpp"

vector<int> getMaxMatrix(vector<vector<int>> &matrix) {
    vector<vector<int>> prefix(matrix);
    vector<int> ans(4);
    for (int j = 0; j < prefix[0].size(); j++) {
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i][j] += prefix[i - 1][j];
        }
    }
    int globalMax = INT32_MIN;
    for (int bottom = 0; bottom < prefix.size(); bottom++) {
        for (int top = bottom; top < prefix.size(); top++) {
            vector<int> b(matrix.front().size());
            if (bottom > 0) {
                for (int j = 0; j < b.size(); j++) {
                    b[j] = prefix[top][j] - prefix[bottom - 1][j];
                }
            } else {
                b = prefix[top];
            }
            int left = 0;
            int tempMax = INT32_MIN;
            for (int right = 0; right < b.size(); right++) {
                if (tempMax < 0) {
                    left = right;
                    tempMax = b[left];
                } else {
                    tempMax += b[right];
                }
                if (tempMax > globalMax) {
                    globalMax = tempMax;
                    ans[0] = bottom;
                    ans[1] = left;
                    ans[2] = top;
                    ans[3] = right;
                }
            }
        }
    }
    return ans;
}