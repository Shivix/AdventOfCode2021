#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

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

void turnLeft90(int& xAxis, int& yAxis){
	std::swap(xAxis, yAxis);
    xAxis = -xAxis;
}

void turnRight90(int& xAxis, int& yAxis){
	std::swap(xAxis, yAxis);
    yAxis = -yAxis;
}

void turn180(int& xAxis, int& yAxis){
	xAxis = -xAxis;
   	yAxis = -yAxis;
}

int main() {
    std::ifstream fileStream {"input.txt"};
    int direction{90}; // ship starts facing east
    int xAxis{0}; // +east/ -west
    int yAxis{0}; // +north / -south
	
	const std::vector<std::string> coordinatesVec{std::istream_iterator<std::string>{fileStream}, {}};
	// part 1
    for (const auto& coordinate: coordinatesVec) {
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
    std::cout << "Part 1: " << std::abs(xAxis) + std::abs(yAxis) << std::endl;

	// part 2
	xAxis = 10;
	yAxis = 1;
    int shipXAxis{0};
    int shipYAxis{0};
	for(const auto& coordinate: coordinatesVec){
		const int value{std::stoi(coordinate.substr(1))};
      	const char instruction{coordinate.front()};
        
		switch (instruction)
        {
            case 'L':
                if (value == 90){
					turnLeft90(xAxis, yAxis);
                }
                else if (value == 180){
					turn180(xAxis, yAxis);
                }
                else if (value == 270){
					turnRight90(xAxis, yAxis);
                }
                break;
            case 'R':
                if (value == 90){
					turnRight90(xAxis, yAxis);
                }
                else if (value == 180){
					turn180(xAxis, yAxis);
                }
                else if (value == 270){
					turnLeft90(xAxis, yAxis);
                }
                break;
			case 'F':
                shipXAxis += (xAxis * value);
                shipYAxis += (yAxis * value);
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
    std::cout << "Part 2: " << std::abs(shipXAxis) + std::abs(shipYAxis) << std::endl;
}

