#include <iostream>
#include <deque>
#include <vector>

std::deque<int> addVec(std::deque<int> deq,std::vector<int>& vec){
    for(int num : vec){
        deq.push_back(num);
    }
    return deq;
}

int main(){
    std::deque<int> deq = {1, 2, 3, 4};
    std::vector<int> vec = {5, 6, 7};
    
    deq = addVec(deq,vec);

    std::cout<< " {";
    for(int num : deq){
        std::cout<< num;
        if(num != deq.back()){
            std::cout << ", ";
        }
    }
    std::cout<< "}"<< std::endl;
return 0;
}
