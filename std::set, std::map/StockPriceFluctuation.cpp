#include <iostream>
#include <vector>
#include <map>

class StockPrice
{
    std::map<int, int> prices;
    std::map<int, int, std::greater<int>> reverse_prices;

public:
StockPrice(){}
    void update(int timestamp, int price)
    {
        if (prices.find(timestamp) != prices.end())
        {
            int prevPrice = prices[timestamp];
            reverse_prices.erase(prevPrice);
        }
        prices[timestamp] = price;
        reverse_prices[price]++;
    }
    int current()
    {
        return prices.rbegin()->second;
    }
    int maximum()
    {
        return reverse_prices.begin()->first;
    }
    int minimum()
    {
        return reverse_prices.rbegin()->first;
    }
};

int main()
{
    StockPrice stock;
    std::vector<std::string> actions = {"StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"};
    std::vector<std::vector<int>> values = {{}, {1, 10}, {2, 5}, {}, {}, {1, 3}, {}, {4, 2}, {}};
    for (int i = 0; i < actions.size(); ++i)
    {
        if (actions[i] == "StockPrice")
        {
            continue;
        }
        else if (actions[i] == "update")
        {
            stock.update(values[i][0], values[i][1]);
        }
        else if (actions[i] == "current")
        {
            std::cout << stock.current() << std::endl;
        }
        else if (actions[i] == "maximum")
        {
            std::cout << stock.maximum() << std::endl;
        }
        else if (actions[i] == "minimum")
        {
            std::cout << stock.minimum() << std::endl;
        }
    }
return 0;
}
