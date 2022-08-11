#include "regular_headers.hpp"

int videoStitching(vector<vector<int>> &clips, int time) {
    vector<int> maxn(time, 0);
    for (int i = 0; i < time; i++) {
        maxn[clips[i][0]] = max(maxn[clips[i][0]], clips[i][1]);
    }
    int pre = 0;
    int count = 0;
    int last = 0;
    for (int i = 0; i < time; i++) {
        last = max(last, maxn[i]);
        if (i == last) {
            return -1;
        }
        if (i == pre) {
            count++;
            pre = last;
        }
    }
    return count;
}
// int videoStitching(vector<vector<int>> &clips, int time) {
//     vector<int> maxn(time);
//     int last = 0, ret = 0, pre = 0;
//     for (vector<int> &it : clips) {
//         if (it[0] < time) {
//             maxn[it[0]] = max(maxn[it[0]], it[1]);
//         }
//     }
//     for (int i = 0; i < time; i++) {
//         last = max(last, maxn[i]);
//         if (i == last) {
//             return -1;
//         }
//         if (i == pre) {
//             ret++;
//             pre = last;
//         }
//     }
//     return ret;
// }

int main() {
    vector<vector<int>> clips{{5, 7}, {1, 8}, {0, 0}, {2, 3}, {4, 5}, {0, 6}, {5, 10}, {7, 10}};
    cout << videoStitching(clips, 5);
}