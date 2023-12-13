#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::map<int, int> numIndices;
    std::vector<int> result;

    for(int i = 0; i < nums.size(); ++i){
        int complement = target - nums[i];
        if(numIndices.find(complement) != numIndices.end()){
            result.push_back(numIndices[complement]);
            result.push_back(i);
            return result;
        }
        numIndices[nums[i]] = i;
    }
    return result;
}

int main(){
    std::vector<int> nums = {3,3};
    int target = 6;
    std::vector<int> indices = twoSum(nums, target);
    if(!indices.empty()){
        std::cout<<"[" << indices[0] << ","<< indices[1] << "]" << std::endl;
    }
    else{
        std::cout<<"No two elements add up to the target"<< std::endl;
    }
    return 0;
}
