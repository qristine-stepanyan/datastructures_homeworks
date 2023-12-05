#include <iostream>
#include <map>

class MyCalendar
{

private:
std::map<int, int> myMap;

public:
bool book (int start,int end)
{
    auto it = myMap.begin();
    while (it != myMap.end() && it -> first < start)
    {
        if (it->second > start)
        {
            return false;
        }
        ++it;
    }
    if (it != myMap.end() && it -> first < end)
    {
        return false;
    }
    myMap[start] = end;
    return true;
}
};

int main()
{
    MyCalendar myCalendar{};
    std::cout<< myCalendar.book(10, 20) << std::endl;
    std::cout<< myCalendar.book(15, 25) << std::endl;
    std::cout<< myCalendar.book(20, 30) << std::endl;
}