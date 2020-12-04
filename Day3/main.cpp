#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>

int checkTreesHit(std::vector<std::string>& mountain, int rightJump, int downJump){
	int treeCounter{0};
	for(size_t i{0}, j{0}; i < mountain.size(); i += downJump){
		if (mountain[i][j % mountain[0].size()] == '#') {
			++treeCounter;
		}
		j += rightJump;
	}
	return treeCounter;
}
int main(){
	std::vector<std::pair<int, int>> jumpsList{
		{1, 1},
		{3, 1},
		{5, 1},
		{7, 1},
		{1, 2}
	};
	std::ifstream file{"input.txt"};
	std::vector<std::string> mountain{std::istream_iterator<std::string>{file}, {}};
	long productOfTreesHit{1};
	for(auto&& i: jumpsList){
		productOfTreesHit *= checkTreesHit(mountain, i.first, i.second);
	}
	std::cout << productOfTreesHit << std::endl;
	return 0;
}
