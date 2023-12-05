#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>

int main () {

	std::ifstream fileIn {"input.txt"};

	if(fileIn.bad()) {
		std::cout << "Error al abrir el stream.\n";
	}

	std::string line {};
	int total {0};

	while(!fileIn.eof()) {
		std::getline(fileIn, line);

		std::vector<char> numbers {};
		std::string letterNumb {};
		int number {0};

		if(!line.empty()) {
			std::cout << line << '\n';
			for(size_t i = 0; i < line.size(); i++) {

				if(std::isdigit(line[i])) {
					numbers.push_back(line[i]);
				}
			}

			letterNumb += numbers.front();
			letterNumb += numbers.back();
			number = std::stoi(letterNumb);
			std::cout << "Number: " << number << '\n';
			

			std::cout << total << '\n';
			std::cout << '\n';
		}

		total += number;
	}

	std::cout << "Total: " << total << '\n';
   return 0;
}
