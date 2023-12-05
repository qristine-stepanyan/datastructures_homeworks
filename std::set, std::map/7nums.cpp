#include <iostream>
#include <vector>
#include <map>

bool duplicate(std::vector<int>& nums, int k)
{
    std::map<int, int> numIndex;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (numIndex.find(nums[i]) != numIndex.end() && i - numIndex[nums[i]] <= k)
        {
            return true;
        }
        numIndex[nums[i]] = i;
    }
return false;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    std::cout << duplicate(nums, k);
    return 0;
}
