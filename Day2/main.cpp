#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

int main(){
	
	
	std::ifstream file{"input.txt"};
	std::vector<std::string> fileData{std::istream_iterator<std::string>{file}, {}};

    int num{3};
    char character;
    int lowerRange, upperRange;
    int validPasswords{0};
    for(auto i: fileData){
		// grab numbers
		if(num % 3 == 0){
            lowerRange = std::stoi(i);
            i.erase(0, i.find('-') + 1);
            upperRange = std::stoi(i);
        }
		// grab character
		else if(num % 3 == 1){
		    character = i.front();
		}
		else{
            //auto count{std::count(i.begin(), i.end(), character)};
            if((i[lowerRange - 1] == character) ^ (i[upperRange - 1] == character)){
                ++validPasswords;
            }
		}
		++num;
	}
    std::cout << validPasswords;
}
