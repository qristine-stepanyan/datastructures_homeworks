#include <iostream>
#include <map>

class MyCalendarTwo
{
    std::map<int, int> a;

public:
MyCalendarTwo(){}
    bool book(int start, int end)
    {
        a[start]++;
        a[end]--;
        int active = 0;
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            active += it->second;
            if (active >= 3)
            {
                a[start]--;
                a[end]++;
                if (a[start] == 0) a.erase(start);
                if (a[end] == 0) a.erase(end);
                return false;
            }
        }
        return true;
    }
};

int main()
{
    MyCalendarTwo myCalendarTwo;
    std::cout << myCalendarTwo.book(10, 20) << std::endl; 
    std::cout << myCalendarTwo.book(50, 60) << std::endl; 
    std::cout << myCalendarTwo.book(10, 40) << std::endl; 
    std::cout << myCalendarTwo.book(5, 15) << std::endl;  
    std::cout << myCalendarTwo.book(5, 10) << std::endl; 
    std::cout << myCalendarTwo.book(25, 55) << std::endl; 
return 0;
}
