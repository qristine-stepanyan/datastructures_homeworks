#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

void kMostFrequentElements(const std::vector<int>& arr, int k){
    std::unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        frequencyMap[num]++;
    }
    struct Compare {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const{
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second < b.second;
        }
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> p;
    for (auto& pair : frequencyMap) {
        p.push(pair);
    }
    while (k-- && !p.empty()) {
        std::cout << p.top().first << " ";
        p.pop();
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;
    kMostFrequentElements(arr, k);
    return 0;
}
