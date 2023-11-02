#include <iostream>
#include <deque>

std::deque<int> arrange(std::deque<int>& deq){
    std::deque<int> result;
    for(int num : deq){
        if(num % 2 == 0){
            result.push_back(num);
        }
    }
    for(int num : deq){
        if(num % 2 != 0){
            result.push_back(num);
        }
    }
    return result;
}

int main(){
    std::deque<int> deq = {1, 2, 3, 4, 5, 6};
    std::deque<int> arranged = arrange(deq);
    std::cout<< " {";
    for(int num : arranged){
        std::cout<< num;
        if(num != arranged.back()){
            std::cout << ", ";
        }
    }
    std::cout<< "}"<< std::endl;
return 0;
}