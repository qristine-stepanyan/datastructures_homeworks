#include <iostream>
#include <vector>
#include <string>
#include <map>

int count(std::vector<std::string>& words, const std::string& chars){
    std::map<char, int> charCount;
    for (char c : chars) {
        charCount[c]++;
    }
    int length = 0;
    for (const std::string& word : words){
        std::map<char, int> wordCount;
        bool good = true;
        for (char c : word){
            wordCount[c]++;
            if (wordCount[c] > charCount[c]){
                good = false;
                break;
            }
        }
        if (good){
            length += word.size();
        }
    }
return length;
}

int main(){
    std::vector<std::string> words = {"hello", "world", "leetcode", "tree"};
    std::string chars = "welldonehoneyr";
    std::cout<< count(words, chars) << std::endl;
    return 0;
}
