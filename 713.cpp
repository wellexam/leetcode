#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> temp(size, 0);
    vector<vector<int>> product(size, temp);
    for (int i = 0; i < size; ++i) {
        product[i][i] = nums[i];
    }
    
}