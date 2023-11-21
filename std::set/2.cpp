#include <iostream>
#include <set>

std::set<int> setUnion(std::set<int> &set1,std::set<int> &set2)
{
    std::set<int> resultSet = set1;
    for(int element : set2)
    {
        resultSet.insert(element);
    }
    return resultSet;
}

std::set<int> setIntersection(std::set<int> &set1,std::set<int> &set2)
{
    std::set<int> resultSet;
    for(int element : set1){
        if(set2.find(element) != set2.end())
        {
            resultSet.insert(element);
        }
    }
    return resultSet;
}

std::set<int> setDifference(std::set<int> &set1,std::set<int> &set2)
{
    std::set<int> resultSet;
    for(int element : set1)
    {
        if(set2.find(element) == set2.end())
        {
            resultSet.insert(element);
        }
    }
    return resultSet;
}

int main()
{
    std::set<int> setA = {1,2,3,4,5};
    std::set<int> setB = {3,4,5,6,7};

    // Union
    std::set<int> unionSet = setUnion(setA,setB);
    std::cout << "Union of sets: ";
    for(int element : unionSet)
    {
        std::cout<< element<< " ";
    }
    std::cout<< std::endl;

    // Intersection
    std::set<int> intersectionSet = setIntersection(setA,setB);
    std::cout << "Intersection of sets(A - B): ";
    for(int element : intersectionSet)
    {
        std::cout<< element << " ";
    }
    std::cout<< std::endl;

    // Difference
    std::set<int> differenceSet = setDifference(setA,setB);
    std::cout << "Difference of sets: ";
    for(int element : differenceSet)
    {
        std::cout<< element << " ";
    }
    std::cout<< std::endl;

return 0;
}
