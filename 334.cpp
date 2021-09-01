#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int min = INT_MAX, mid = INT_MAX;
    for (auto i : nums)
    {
        if (i <= min)
            min = i;
        else if(i <= mid)
            mid = i;
        else
            return true;
    }
    return false;
}