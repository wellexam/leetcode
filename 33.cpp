#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int len = nums.size();
        int p = 0;
        if (len == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        while (p < len - 1 && nums[p] < nums[p + 1]) {
            ++p;
            if (p == len - 1) {
                p = 0;
                break;
            }
        }
        if (nums[p] == target)
            return p;
        else if (nums[p] < target && p != 0)
            return -1;
        else if (nums[len - 1] >= target || p == 0) {
            int beg = p + 1, end = len - 1;
            int pos = (beg + end) / 2;
            while (nums[pos] != target) {
                if (beg == pos || pos == end) {
                    if (nums[beg] == target)
                        pos = beg;
                    if (nums[end] == target)
                        pos = end;
                    break;
                }
                if (nums[pos] > target) {
                    end = pos;
                    pos -= (pos - beg) / 2;
                } else {
                    beg = pos;
                    pos += (end - pos) / 2;
                }
            }
            if (nums[pos] == target)
                return pos;
            else
                return -1;
        } else {
            int beg = 0, end = p;
            int pos = (beg + end) / 2;
            while (nums[pos] != target) {
                if (beg == pos || pos == end) {
                    if (nums[beg] == target)
                        pos = beg;
                    if (nums[end] == target)
                        pos = end;
                    break;
                }
                if (nums[pos] > target) {
                    end = pos;
                    pos -= (pos - beg) / 2;
                } else {
                    beg = pos;
                    pos += (end - pos) / 2;
                }
            }
            if (nums[pos] == target)
                return pos;
            else
                return -1;
        }
    }
};

int main() {
    vector<int> a = {3, 5, 1};
    Solution p;
    auto r = p.search(a, 1);
    cout << r << endl;
    return 0;
}