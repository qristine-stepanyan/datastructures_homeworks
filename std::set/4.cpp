#include <iostream>
#include <vector>
#include <set>

std::set<int> commonElements(std::vector<std::set<int>>& sets)
{
    if(sets.empty())
    {
        return std::set<int>(); 
    }

    std::set<int> result = sets[0];

    for(const auto& s : sets)
    {
        std::set<int> intersection;
        for(int elem : s)
        {
            if(result.find(elem) != result.end())
            {
                intersection.insert(elem);
            }
        }
        result = intersection;
    }
  return result;
}

int main()
{
    std::set<int> set1 = {1,2,3,4};
    std::set<int> set2 = {3,4,5,6};
    std::set<int> set3 = {4,3,6,7};

    std::vector<std::set<int>> sets = {set1, set2, set3};
    std::set<int> common = commonElements(sets);

    for(int elem : common)
    {
        std::cout<< elem<< " ";
    }

return 0;
}
