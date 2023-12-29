//Import of libraries
#include <iostream>
#include <fstream>
#include <vector>
#include "AdventFunctions.cpp"

//Function declarations
void splitTheDataInto (std::vector<std::string> &dataAr, std::vector<std::string> &orders, std::vector<int> &nums);
void printRegister (int cycle, int reg);
 
//Program
int main() {
	//Variables
	std::vector<std::string> dataArray;
	std::vector<std::string> instructions;
	std::vector<int> numbers;

	std::vector<int> cyclesAndRegister;
	int reg = 1;
	int totalSignalStrength = 0;

	dataArray = openFileAndFetchData("input.txt");
	splitTheDataInto(dataArray, instructions, numbers);

	cyclesAndRegister.clear();
	cyclesAndRegister.push_back(reg);

	for(int i = 0; i < instructions.size(); i++) {
		if(instructions[i] == "noop") {
			cyclesAndRegister.push_back(numbers[i]);
		}
		else if(instructions[i] == "addx") {
			cyclesAndRegister.push_back(0);
			cyclesAndRegister.push_back(numbers[i]);
		}
		else {
			std::cout << "Error with the register." << std::endl;
		}
	}

	for(int i = 0; i < cyclesAndRegister.size(); i++) {
		std::cout << "Cycle: " << i << " , Reg: " << cyclesAndRegister[i] << std::endl;
	}

	for(int i = 1; i < cyclesAndRegister.size(); i++) {
		switch (i) {
			case 20:	
			case 60:
			case 100:
			case 140:
			case 180:
			case 220:
				std::cout << "La fuerza de la señal es " << i*reg << std::endl;
				std::cout << "El ciclo es " << i << " y el registro es " << reg << std::endl;
				totalSignalStrength += (i*reg);
				printRegister(i, reg);
				break;	
			default:
				break;
		}
		reg += cyclesAndRegister[i];
	}
		
	std::cout << "Los ciclos totales son: " << cyclesAndRegister.size() << std::endl;
	std::cout << "The total signal strength is: " << totalSignalStrength << std::endl;

	return 0;
}

//Print the register
void printRegister (int cycle, int reg) {
	std::cout << "En el ciclo " << cycle << " el regsitro es igual a " << reg << std::endl;
}

//Split each line from the data array into intructions and its numbers
void splitTheDataInto (std::vector<std::string> &dataAr, std::vector<std::string> &orders, std::vector<int> &nums) {
	std::string line;
	std::string order;
	int num;

	for(int i = 0; i < dataAr.size(); i++) {
		line = dataAr[i];
		order = line.substr(0, line.find(" "));

		if(order == "noop") {
			num = 0;
		}
		else {
			num = stoi(line.substr(line.find(" ") + 1));
		}

		orders.push_back(order);
		nums.push_back(num);
	}
}


