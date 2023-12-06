#include <iostream>
#include <queue>
#include <vector>

std::vector<int> kLargestEl(const std::vector<int>& nums,int k){
    std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
    for(int num : nums){
        minHeap.push(num);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    std::vector<int> result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }
return result;
}

int main()
{
    std::vector<int> vec = {-1, 1, 9, 0, 5, 6};
    int k = 4;
    std::vector<int> largest = kLargestEl(vec,k);
    for(int num : largest){
        std::cout << num << " ";
    }
    std::cout<< std::endl;
return 0;
}
