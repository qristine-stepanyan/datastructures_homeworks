#include <iostream>
#include <vector>
#include <set>

void removeDuplicates(std::vector<int> &arr)
{
    std::set<int> unique;
    for(int num : arr)
    {
        unique.insert(num);
    }
    arr.clear();
    for(int num : unique)
    {
        arr.push_back(num);
    }
}

int main()
{
    std::vector<int> numbers = {1,2,2,3,4,4,5};
    removeDuplicates(numbers);
    for(int num : numbers)
    {
        std::cout<< num<< " ";
    }
    std::cout<< std::endl;
    
return 0;
}