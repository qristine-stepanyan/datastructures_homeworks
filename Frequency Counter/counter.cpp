#include <iostream>
#include <map>
#include <string>

std::string count(std::string &s){
    std::string lowercase = s;
    for (char &c : lowercase) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; 
        }
    }
    return lowercase;
}
int main(){
    std::string v;
    std::getline(std::cin, v);
    std::map<std::string, int> frequency;
    std::string word;
    std::string cur;
    for(char &c : v){
        if(std::isalpha(c)){
            cur += std::tolower(c);
        }
        else
        {
            if(!cur.empty()){
                ++frequency[cur];
                cur.clear();
            }
        }
    }
    if(!cur.empty()){
        ++frequency[cur];
    }
    for(const auto &pair : frequency){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
return 0;
}






































































