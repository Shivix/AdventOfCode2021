#include <iostream>
#include <fstream>
#include <vector>

int main(){
    
    std::fstream file{"input.txt"};
    std::vector<std::string> fileData{};
    std::string temp{};
    std::string temp2{};
    while (std::getline(file, temp2)){
        temp += temp2;
        if (file.peek() == '\n' || file.eof()) {
            fileData.emplace_back(temp);
            temp.clear();
        }
    }
    int sum{0};
    for(auto& i: fileData){
        std::sort(i.begin(), i.end());
        i.erase(std::unique(i.begin(), i.end()), i.end());
        sum += i.size();
    }
    std::cout << sum;
}