#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <regex>


int main(){
	std::fstream file{"input.txt"};
	std::vector<std::string> fileData{};
	std::string temp{};
	std::string temp2{};
	while (std::getline(file, temp2)){
	    temp += temp2;
		if (file.peek() == '\n' || file.eof()) {
			fileData.emplace_back(temp);
			temp = "";
		}
	}
    
	auto validPassports{std::count_if(fileData.begin(), fileData.end(), [](const std::string& passport){
        return std::regex_search(passport,std::regex("^(?=.*byr)(?=.*iyr)(?=.*eyr)(?=.*hgt)(?=.*hcl)(?=.*ecl)(?=.*pid).*$"));
	})};
	std::cout << validPassports;
}
