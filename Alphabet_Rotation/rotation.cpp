#include <iostream>
#include <vector>

bool equivalent(const std::string& v1,const std::string& v2){
    for(int k = 0; k < 26; ++k){
        std::string rot= v1;
        for(char& c : rot){
            c = 'a' + (c - 'a' + k) % 26;
        }
        if(rot== v2){
            return true;
        }
    }
return false;
}
std::vector<int> findEl(const std::vector<std::string>& v){
    int n = v.size();
    std::vector<int> result;

    for(int i = 0; i < n; ++i){
        bool found = false;
        for(int j = 0; j < n; ++j){
            if(j != i && equivalent(v[i],v[j])){
                found= true;
                break;
            }
        }
        result.push_back(found ? 1 : 0);
    }
return result;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::string> arr(n);
    for (int i = 0; i < n; ++i){
        std::cin >> arr[i];
    }
    std::vector<int> result = findEl(arr);
    for(int verj : result){
        std::cout << verj << '\n';
    }
return 0;
}
