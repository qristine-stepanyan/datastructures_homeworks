#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

std::vector<std::vector<std::string>> findPairs(std::vector<std::vector<std::string>>& dishes)
{
    std::map<std::string, std::vector<std::string>> ingredients;
    for (const auto& dish : dishes)
    {
        std::string dishName = dish[0]; 
        for (int i = 1; i < dish.size(); ++i)
        {
            ingredients[dish[i]].push_back(dishName);
        }
    }
    std::vector<std::vector<std::string>> result;
    for (const auto& a : ingredients)
    {
        if (a.second.size() >= 2)
        { 
            std::vector<std::string> temp = { a.first }; 
            std::vector<std::string> dishesList = a.second; 
            for (int i = 0; i < dishesList.size() - 1; ++i){
                for (int j = 0; j < dishesList.size() - i - 1; ++j){
                    if (dishesList[j] > dishesList[j + 1]) {
                        std::swap(dishesList[j], dishesList[j + 1]);
                    }
                }
            }
            temp.insert(temp.end(), dishesList.begin(), dishesList.end());
            result.push_back(temp); 
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<std::string>> dishes = {
        {"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
        {"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
        {"Quesadilla", "Chicken", "Cheese", "Sauce"},
        {"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}
    };
    std::vector<std::vector<std::string>> result = findPairs(dishes);
    std::cout<< "solution(dishes) = [";
    for (const auto& dish : result)
    {
        std::cout << "[";
        for (const auto& ingredient : dish)
        {
            std::cout << "'" << ingredient << "'" << ",";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]";
return 0;
}
