#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
    int count = 0;
    unordered_map<int, int> map;
    int sum = 0;
    map[sum] = 1;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        auto pos = map.find(sum);
        if (pos == map.end())
            map.insert({sum, 1});
        else
            ++map[sum];
        pos = map.find(sum - k);
        if (pos != map.end())
            count += pos->second;
    }
    return count;
}