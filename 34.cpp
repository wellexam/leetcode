#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        int len = nums.size();
        if (!len)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int beg = 0, end = len - 1;
        int pos = len / 2;
        while (nums[pos] != target)
        {
            if (beg == pos || pos == end)
            {
                if (nums[beg] == target)
                    pos = beg;
                if (nums[end] == target)
                    pos = end;
                break;
            }
            if (nums[pos] > target)
            {
                end = pos;
                pos -= (pos - beg) / 2;
            }
            else
            {
                beg = pos;
                pos += (end - pos) / 2;
            }
        }
        if (nums[pos] != target)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else
        {
            beg = pos;
            end = pos;
            while (++end < len && nums[end] == target)
            {
                continue;
            }
            --end;
            while (--beg >= 0 && nums[beg] == target)
            {
                continue;
            }
            ++beg;
            result.push_back(beg);
            result.push_back(end);
            return result;
        }
    }
};

int main()
{
    vector<int> a = {1, 3};
    Solution p;
    auto r = p.searchRange(a, 1);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}