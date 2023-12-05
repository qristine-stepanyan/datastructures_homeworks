#include <iostream>
#include <vector>
#include <set>

class Solution
{
    struct Item
    {
        bool operator()(const std::vector<int>& l, const std::vector<int>& r) const
        {
            return l[0] < r[0];
        }
    };

public:
    std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2)
    {
        std::set<std::vector<int>, Item> all;
        for (auto item : items1)
        {
            all.insert(item);
        }
        for (auto item : items2)
        {
            auto itemIt = all.find(item);
            if (itemIt == all.end())
            {
                all.insert(item);
            }
            else
            {
                std::vector<int> newIt = {item[0], item[1] + (*itemIt)[1]};
                all.erase(itemIt);
                all.insert(newIt);
            }
        }
        std::vector<std::vector<int>> result;
        for (auto item : all)
        {
            result.push_back({item[0], item[1]});
        }
        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> items1 = {{1, 3}, {2, 2}};
    std::vector<std::vector<int>> items2 = {{7, 1}, {2, 2}, {1, 4}};
    Solution solution;
    std::vector<std::vector<int>> mergedItems = solution.mergeSimilarItems(items1, items2);
    std::cout<< "[ ";
    for (const auto& item : mergedItems)
    {
        std::cout << "["<< item[0] << "," << item[1] << "]"<< " ";
    }
    std::cout<< "]";
    return 0;
}
