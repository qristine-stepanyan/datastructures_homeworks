#include <iostream>
#include <set>

int main()
{
    int maxSize;
    std::cout<< "Enter the maximum size of the set: ";
    std::cin>> maxSize;
    
    std::set<int> mySet;
    int choice = 0;
    while(choice != 3)
    {
        std::cout << "\nMenu:\n"
                  << "1. Add an element\n"
                  << "2. List elements\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        std::cin>> choice;
        switch(choice)
        {
            case 1:
            {
                int newElement;
                std::cout<< "Enter the element to add: ";
                std::cin>> newElement;
                mySet.insert(newElement);
                if(mySet.size() > maxSize)
                {
                    auto lastElement = --mySet.end();
                    mySet.erase(lastElement);
                    std::cout<< "Size limit exceeded. Last added element removed.\n";
                }
                break;
            }
            case 2:
            {
                std::cout<< "Elements in the set: ";
                for(int element : mySet)
                {
                    std::cout<< element<< " ";
                }
                std::cout<< std::endl;
                break;
            }
            case 3:
            {
                std::cout<< "Exiting the program.\n";
                break;
            }
            default:
            {
                std::cout<< "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

return 0;
}

 