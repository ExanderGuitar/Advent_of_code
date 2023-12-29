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

	std::string rawValue1;
	std::string rawValue2;
	std::string rawValue3;

	char match;
	int letterValue = 0;
	int sumLetterValues = 0;

	while (inputData) {
		std::getline(inputData, rawValue1);
		std::getline(inputData, rawValue2);
		std::getline(inputData, rawValue3);
		
		if(rawValue1.empty()) {
			break;
		}

		std::cout << rawValue1 << std::endl;
		std::cout << rawValue2 << std::endl;
		std::cout << rawValue3 << std::endl;
		std::cout << std::endl;

		for(int i = 0; i < rawValue1.size(); i++) {
			for(int j = 0; j < rawValue2.size(); j++) {
				for (int k = 0; k < rawValue3.size(); k++) {
					if(rawValue1[i] == rawValue3[k] && rawValue2[j] == rawValue3[k]) {
						match = rawValue3[k];
					}
				}
			}
		}

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
