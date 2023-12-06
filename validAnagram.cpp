#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string s,std::string t){
    if(s.length() != t.length())
    {
        return false;
    }
    std::map<char,int> count;
    for(char ch : s){
        count[ch]++;
    }
    for(char ch : t){
        if(count.find(ch) == count.end() || count[ch] == 0){
            return false; 
        }
        count[ch]--;
    }
return true; 
}

int main(){
    std::string s,t;
    std::cin>> s >> t;
    bool result = isAnagram(s,t);
    std::cout << (result? "true":"false");

return 0;
}