#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	std::ifstream inputData;
	inputData.open("input.txt");

	if (inputData.fail()) {
		std::cerr << "Problema al cargar el archivo." << std::endl;
	}
	else {
		std::cout << "Archivo cargado con exito." << std::endl;
	}

	std::string rawValue;
	std::string chain1;
	std::string chain2;
	std::vector <char> matches;
	char match;
	int letterValue;
	int sumLetterValues = 0;

	while (inputData) {
		std::getline(inputData, rawValue);
		std::cout << rawValue << std::endl;
		std::cout << rawValue.size() << std::endl;
		chain1 = rawValue.substr(0, rawValue.size()/2);
		chain2 = rawValue.substr(rawValue.size()/2, rawValue.size()/2);

		std::cout << "Chain 1: " << chain1 << std::endl;
		std::cout << "Chain 2: " << chain2 << std::endl;
	
		for(int i = 0; i < chain1.size(); i++) {
			for(int j = 0; j < chain2.size(); j++) {
				if (chain1[i] == chain2[j]) {
					if (matches.empty()) {
						matches.push_back(chain2[j]);
					}
					else {
						if (matches.back() != chain2[j]) {
							matches.push_back(chain2[j]);
						}
					}
				}
			}
		}

		std::cout << "The matches are: ";
		for(int i = i; i < matches.size(); i++) {
			std::cout << matches[i] << " ";
		}
		match = matches.back();
		letterValue = int(match);
		
		if (islower(match)) {
			letterValue -= 96;
		}
		else {
			letterValue -= 38;
		}

		sumLetterValues += letterValue; 
		std::cout << match << " " << letterValue << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "La suma total es: " << sumLetterValues << std::endl;
	inputData.close();
	return 0;
}
