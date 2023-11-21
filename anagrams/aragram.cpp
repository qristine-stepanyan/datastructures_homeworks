#include <iostream>
#include <vector>
#include <string>
#include <set>

bool areEquivalent(std::string& word1,std::string& word2)
{
    std::set<char> setWord1(word1.begin(),word1.end());
    std::set<char> setWord2(word2.begin(),word2.end());
    return setWord1 == setWord2;
}

int largestEquivalentSubset(std::vector<std::string>& words)
{
    int largestSubset = 0;
    std::vector<bool> visited(words.size(),false);
    for(int i = 0; i < words.size(); ++i){
        if(!visited[i]){
            int subsetSize = 1; 
            visited[i] = true;
            for(int j = i + 1; j < words.size(); ++j){
                if(!visited[j] && areEquivalent(words[i],words[j]))
                {
                    visited[j] = true;
                    ++subsetSize;
                }
            }
            if(subsetSize > largestSubset)
            {
                largestSubset = subsetSize;
            }
        }
    }

return largestSubset;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<std::string> wordList(N);
    for(int i = 0; i < N; ++i)
    {
        std::cin>> wordList[i];
    }
    int result = largestEquivalentSubset(wordList);
    std::cout<< result << std::endl;

return 0;
}
