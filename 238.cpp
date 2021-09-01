#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector< int > productExceptSelf(vector< int > &nums)
{
    vector< int > prod;
    prod.reserve(nums.size());
    prod.push_back(1);
    prod.push_back(nums[0]);
    for (int i = 2; i < nums.size(); ++i)
    {
        prod.push_back(prod[i - 1] * nums[i - 1]);
    }
    for (int i = nums.size() - 2; i >= 0; --i)
    {
        nums[i] *= nums[i + 1];
        prod[i] *= nums[i + 1];
    }
    return prod;
}

int main()
{
    vector<int> p = {1,2,3,4};
    auto ans = productExceptSelf(p);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}