#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>

int main(){
	
	std::ifstream file{"input.txt"};
	std::vector<std::string> fileData{std::istream_iterator<std::string>{file}, {}};
	std::vector<std::vector<std::string>::iterator> usedInstructions{};
	[[maybe_unused]] int accumulator{0};
	for(auto i{fileData.begin()}; i != fileData.end(); i+=2){
		// check for loop
		for(auto j: usedInstructions){
			if(j == i){
				std::cout << "Infinite loop detected -- Acumulator = " << accumulator << std::endl;
				return 0;
			}
		}
		// get instruction and value
		auto instruction = *i;
		usedInstructions.emplace_back(i);
		int value = std::stoi(*(i + 1));
		// perform instruction
		if (instruction == "acc") {
			accumulator += value;
		}
		else if(instruction == "jmp"){
            i += ((value - 1) * 2);
		}else{
			
		}
		
	}
	
}
