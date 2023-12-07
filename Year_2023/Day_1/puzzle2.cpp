#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>

void replaceTextNumber(std::string& str);

int main() {

	std::ifstream fileIn {"input.txt"};

	if(fileIn.bad()) {
		std::cout << "Error al abrir el archivo.\n";
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
			replaceTextNumber(line);

			for(size_t i = 0; i < line.size(); i++) {
				
				if(std::isdigit(line[i])) {
					numbers.push_back(line[i]);
				}
			}

			std::cout << line << '\n';

			letterNumb += numbers.front();
			letterNumb += numbers.back();
			number = std::stoi(letterNumb);
			std::cout << "Number: " << number << '\n';

			std::cout << "TotalAc: " << total << '\n';
		}

		total += number;
	}

	std::cout << "Total: " << total << '\n';
	return 0;
}

void replaceTextNumber(std::string& str) {
		
		for(size_t i = 0; i < str.size(); i++) {

			switch(str[i]) {
				case 'o':
					if(str.substr(i, 3) == "one") {
						str.replace(i, 3, "1");
					}
					break;

				case 'e':
					if(str.substr(i, 5) == "eight") {
						str.replace(i, 5, "8");
					}
					break;	

				case 't':
					if(str.substr(i, 3) == "two") {
						str.replace(i, 3, "2");
					}
					else if(str.substr(i, 5) == "three") {
						str.replace(i, 5, "3");
					}
					break;	

				case 'f':
					if(str.substr(i, 4) == "four") {
						str.replace(i, 4, "4");
					}
					else if(str.substr(i, 4) == "five") {
						str.replace(i, 4, "5");
					}
					break;	

				case 's':
					if(str.substr(i, 3) == "six") {
						str.replace(i, 3, "6");
					}
					else if(str.substr(i, 5) == "seven") {
						str.replace(i, 5, "7");
					}
					break;	

				case 'n':
					if(str.substr(i, 4) == "nine") {
						str.replace(i, 4, "9");
					}
					break;

				default:
					break;
			}
		}
}
