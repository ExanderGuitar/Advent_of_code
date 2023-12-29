//File name: Puzzle11.cpp
//Import libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Class Monkey
struct Monkey {
	int id;
	std::vector<int> items;
	char valueOperator;
	int multiplier;
	int division;
	int trueTest;
	int falseTest;
};

//Function declaration
int getMonkeyID(std::string lineID); 
void getMonkeyItems(std::vector<int> &items, std::string itemsLine); 
void getValueOperatorAndMultiplier(Monkey king, std::string line); 

//Main function
int main() {
	//File management
	std::ifstream dataInput;
	dataInput.open("input.txt");

	if(dataInput.fail()) {
		std::cerr << "Error al abrir el archivo." << std::endl;
	}
	else {
		std::cout << "Exito al abrir el archivo." << std::endl;
	}

	//Variables
	std::string rawLine;
	std::vector<Monkey> monkeyRow;

	while (dataInput) {
		std::getline(dataInput, rawLine);

		if(rawLine.find("Monkey") == 0) {
			Monkey kong;
			
			kong.id = getMonkeyID(rawLine);

			//Get the items line
			std::getline(dataInput, rawLine);
			getMonkeyItems(kong.items, rawLine); 

			//Get value operator and multiplier
			std::getline(dataInput, rawLine);
			getValueOperatorAndMultiplier(kong, rawLine); 

			//Get the divisor
			std::getline(dataInput, rawLine);


			std::cout << rawLine << std::endl;
			std::getline(dataInput, rawLine);
			std::cout << rawLine << std::endl;
			std::getline(dataInput, rawLine);
			std::cout << rawLine << std::endl;
			std::getline(dataInput, rawLine);
			std::cout << rawLine << std::endl;
		}
	}

	return 0;
}	

int getMonkeyID(std::string lineID) {
	int referencePosition = 0;
	char charID;

	referencePosition = lineID.find(":");
	charID = lineID[referencePosition - 1];

	//Char to int convert to ASCII number so 48 is the ASCII value of 0
	return charID - 48;
}
	
void getMonkeyItems(std::vector<int> &items, std::string itemsLine) {
	int dotReference;
	int commaReference;
	int spaceReference;
	std::string numberText;
	int number;

	dotReference = itemsLine.find(":");
	commaReference = itemsLine.find(",");

	//In case there are various items
	if(commaReference >= 0) {
		while(commaReference >= 0) {
			numberText = itemsLine.substr(commaReference - 2, 2);
			number = stoi(numberText);
			items.push_back(number);
	
			commaReference = itemsLine.find(",", commaReference + 1);	
		}
		//For the last item
		spaceReference = commaReference + 1;
		numberText = itemsLine.substr(spaceReference + 1);
		number = stoi(numberText);
		items.push_back(number);	
	}
	else {
		//In case there is only one item
		spaceReference = itemsLine.find(" ", dotReference);
		numberText = itemsLine.substr(spaceReference + 1);
		number = stoi(numberText);
		items.push_back(number);	
	}
}

void getValueOperatorAndMultiplier(Monkey king, std::string line) {
	int oldReference;
	char valueOper;
	char textMultiplier;
	int multiplier;

	oldReference = line.find("old");	

	valueOper = line.substr(oldReference + 2, 1);
	
	textMultiplier = line.substr(oldReference + 4);
	multiplier = stoi(textMultiplier);

	king.valueOperator = valueOper;
	king.multiplier = multiplier;
}




