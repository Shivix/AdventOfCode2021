#include <iostream>
#include <fstream>
#include <string>

char convertToCardinal(int direction){
	if (direction == 0) {
		return 'N';
	}
	else if (direction == 90) {
        return 'E';
	}
	else if (direction == 180) {
		return 'S';
	}
	else if (direction == 270) {
		return 'W';
    }
	return 'F';
}

int main() {
    std::ifstream fileStream {"input.txt"};
    std::string coordinate;   
    int direction{90}; // ship starts facing east
    int xAxis{0}; // +east/ -west
    int yAxis{0}; // +north / -south

    while (std::getline(fileStream, coordinate)) {
        const int value{std::stoi(coordinate.substr(1))};
        const char instruction{
        	[direction](const std::string& input){
				if (input.front() == 'F') {
					return convertToCardinal(direction);
				}
				return input.front();
        	}(coordinate)
        };

        switch (instruction)
        {
            case 'L':
                direction -= value;
                if (direction < 0) {
                    direction += 360;
                }
                break;
            case 'R':
                direction += value;
                if (direction >= 360) { // will never be 360 will instead be 0
                    direction -= 360;
                }
                break;
            case 'N':
                yAxis += value;
                break;
            case 'E':
                xAxis += value;
                break;
            case 'S':
                yAxis -= value;
                break;
            case 'W':
                xAxis -= value;
                break;
            default:
                throw std::runtime_error("Unknown instruction received");
        }
    }
    std::cout << std::abs(xAxis) + std::abs(yAxis) << std::endl;
}

