#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

bool bijective (std::unordered_map <std::string, std::string> s)
{
    std::set <std::string> visited;
    for (auto it = s.begin() ; it != s.end(); ++it)
    {
        std::string value = it -> second;
        if (visited.find(value) != visited.end())
        {
            return false;
        }
        visited.insert(value);
    }
    return true;
}

int main()
{
    std::unordered_map <std::string,std::string> s = {{"abc","qwe"},{"ase","qwe"}};
    std::cout<< bijective(s) <<std::endl;
    return 0;
}



