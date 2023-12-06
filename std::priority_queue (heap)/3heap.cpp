#include <iostream>
#include <queue>
#include <vector>

int minCost(const std::vector<int>& arr){
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(arr.begin(), arr.end());
    int total = 0;
    while (minHeap.size() > 1){
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int cur = first + second;
        total += cur;
        minHeap.push(cur);
    }
    return total;
}

int main(){
    std::vector<int> arr = {4, 3, 2, 6};
    std::cout << minCost(arr) << std::endl;
return 0;
}
