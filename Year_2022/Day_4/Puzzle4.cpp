#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream dataInput;
	dataInput.open("input.txt");
	
	if(dataInput.fail()) {
		std::cerr << "Error al cargar el archivo" << std::endl;
	} else {
		std::cout << "Archivo cargado con exito." << std::endl;
	}

	std::string rawValue;
	std::string elf1;
	std::string elf2;
	int elf1Sector[2];
	int elf2Sector[2];

	int overlap = 0;

	while(dataInput) {
		std::cout << std::endl;

		std::getline(dataInput, rawValue);
		std::cout << rawValue << std::endl;

		if(rawValue.empty()) {
			break;
		}

		size_t pos = rawValue.find(",");
		elf1 = rawValue.substr(0, pos);
		elf2 = rawValue.substr(pos+1, rawValue.size());

		elf1Sector[0] = std::stoi(elf1.substr(0, elf1.find("-")));
		elf1Sector[1] = std::stoi(elf1.substr(elf1.find("-")+1, elf1.size()));
		elf2Sector[0] = std::stoi(elf2.substr(0, elf2.find("-")));
		elf2Sector[1] = std::stoi(elf2.substr(elf2.find("-")+1, elf2.size()));

		std::cout << "Elfo 1: " << elf1 << std::endl;
		std::cout << "Inicio: " << elf1Sector[0] << std::endl;
		std::cout << "Final: " << elf1Sector[1] << std::endl;
		std::cout << "Elfo 2: " << elf2 << std::endl;
		std::cout << "Inicio: " << elf2Sector[0] << std::endl;
		std::cout << "Final: " << elf2Sector[1] << std::endl;

		if(elf2Sector[0] >= elf1Sector[0]) {
			if(elf2Sector[1] <= elf1Sector[1]) {
				overlap += 1;
				std::cout << "Solapamiento 1" << std::endl;
				continue;
			}
			else {
				std::cout << "Puede 1" << std::endl;
			}
		}
	
		if(elf1Sector[0] >= elf2Sector[0]) {
			if(elf1Sector[1] <= elf2Sector[1]) {
				overlap += 1;
				std::cout << "Solapamiento 2" << std::endl;
				continue;
			}
			else {
				std::cout << "Puede 2" << std::endl;
			}
		}
	}

	std::cout << "Hay " << overlap << " solapamientos." << std::endl;
	dataInput.close();
	
	return 0;
}
