#include <iostream>
#include <set>

bool elementOfSet(int number,std::set<int>& set)
{
    return set.find(number) != set.end();
}

int main()
{
    std::set<int> set = {1,3,5,7,9};
    int k = 5;
    if(elementOfSet(k,set))
    {
        std::cout<< k << " is an element of the set"<< std::endl;
    }
    else
    {
        std::cout<< k << " is not an element of the set"<< std::endl;
    }

return 0;
}
