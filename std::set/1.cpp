#include <iostream>
#include <vector>
#include <set>

std::vector<int> findNonRepeatingElements(std::vector<int>& vec)
{
    std::set<int> nonRepeating;
    std::set<int> repeating;

    for(int num : vec)
    {
        if (nonRepeating.count(num))
        {
            nonRepeating.erase(num);
            repeating.insert(num);
        }
        else if(!repeating.count(num))
        { 
            nonRepeating.insert(num);
        }
    }
    std::vector<int> result(nonRepeating.begin(),nonRepeating.end());
    return result;
}

int main()
{
    std::vector<int> numbers = {1,2,3,2,4,5,3,6};
    std::vector<int> result = findNonRepeatingElements(numbers);
    for(int num : result)
    {
        std::cout<< num << " ";
    }

return 0;
}
