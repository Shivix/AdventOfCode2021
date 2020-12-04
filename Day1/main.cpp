#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>


int main(){
	std::fstream file{"input.txt"};
	std::vector<int> fileData{std::istream_iterator<int>{file}, {}};

	for(auto i: fileData){
		for(auto j: fileData){
			for(auto k: fileData){
				if (i + j + k == 2020){
					std::cout << i * j * k << std::endl;
					return 0;
				}
			}
		}
	}
}
