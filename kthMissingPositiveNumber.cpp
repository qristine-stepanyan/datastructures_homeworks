#include <iostream>
#include <vector>
#include <set>

int findKth(const std::vector<int>& arr, int k){
    std::set<int> nums(arr.begin(), arr.end());
    int count = 0;
    int cur = 1;
    while (count < k){
        if (nums.find(cur) == nums.end()){
            count++;
            if (count == k){
                return cur;
            }
        }
        cur++;
    }
return -1;
}

int main(){
    std::vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    std::cout << findKth(arr, k) << std::endl;
    return 0;
}
