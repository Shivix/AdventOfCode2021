#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <cmath>

constexpr int calculate(const std::string_view& input, int lowerRange, int upperRange, size_t currentIndex, char upperChar, char lowerChar){
	if (input[currentIndex] == lowerChar) {
		upperRange = (upperRange + lowerRange) / 2;
	}
	else if (input[currentIndex] == upperChar){
		lowerRange += std::ceil(((upperRange - lowerRange) / 2) + 1);
	}
	else {
		throw std::runtime_error("Invalid character found in string");
	}
	if (lowerRange == upperRange) {
		return lowerRange;
	}
	else{
		return calculate(input, lowerRange, upperRange, ++currentIndex, upperChar, lowerChar);
	}
}

int main(){
	
	std::fstream file{"input.txt"};
	std::vector<std::string> fileData{std::istream_iterator<std::string>{file}, {}};
	std::vector<int> seatIDs{};
	seatIDs.reserve(fileData.size());
	for(const auto& i: fileData) {
		seatIDs.push_back((calculate(i, 0, 127, 0, 'B', 'F')
		           * 8) + calculate(i.substr(7), 0, 7, 0, 'R', 'L'));
	}
	std::sort(seatIDs.begin(), seatIDs.end());
	for(int j{0}; auto i: seatIDs){
        if(i + 2 == seatIDs[++j]){
            std::cout << "Missing Seat: " << i + 1 << '\n';
        }
	}
	std::cout << seatIDs.back();
}
