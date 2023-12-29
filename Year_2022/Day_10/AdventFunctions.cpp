//Import libraries
#include <iostream>
#include <fstream>
#include <vector>

//Open a file and load the data into a vector which is returned
std::vector<std::string> openFileAndFetchData (std::string name) {
	std::vector<std::string> emptyVector;
	std::string rawLine = "";
	std::ifstream dataStream;

	dataStream.open(name);

	if(dataStream.fail()) {
		std::cerr << "Error al abrir el archivo." << std::endl;
	}
	else {
		std::cout << "Exito al abrir el archivo." << std::endl;
	}

	while (dataStream) {
		std::getline(dataStream, rawLine);

		if(rawLine.empty()) {
			break;
		}

		emptyVector.push_back(rawLine);
	}

	return emptyVector;
}
