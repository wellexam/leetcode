#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

void sortColors(vector< int > &nums)
{
    int p0 = 0, p2 = nums.size() - 1, i = 0;
    for (; i <= p2; ++i)
    {
        if (nums[i] == 0)
        {
            int temp = nums[p0];
            nums[p0] = nums[i];
            nums[i] = temp;
            ++p0;
        }
        else if (nums[i] == 2)
        {
            int temp = nums[p2];
            nums[p2] = nums[i];
            nums[i] = temp;
            --p2;
            --i;
        }
    }
    printf("%c", '[');
    for (int j = 0; j < nums.size() - 1; ++j)
    {
        printf("%d,", nums[j]);
    }
    printf("%d]", nums[nums.size() - 1]);
}

int main()
{
    vector< int > nums = {1,2,0};
    sortColors(nums);
    return 0;
}