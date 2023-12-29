#include <iostream>
#include <fstream>
#include <string>

bool checkMarker(std::string);

int main() {
	std::ifstream dataStream;
	dataStream.open("input.txt");

	if(dataStream.fail()) {
		std::cerr << "Error al cargar el archivo." << std::endl;
	}
	else {
		std::cout << "Archivo cargado con exito." << std::endl;
	}

	std::string stream = "";
	std::getline(dataStream, stream);

	std::string marker = "";
	bool isAMarker = false;
	
	for(int i = 0; i < stream.size(); i++) {
		if (stream[i] == ' ') {
			break;
		}

		for(int j = i; j < (i+14); j++) {
			marker.push_back(stream[j]);
		}
		std::cout << marker << std::endl;
		isAMarker = checkMarker(marker);	

		if(isAMarker) {
		//	std::cout << "El marker es: " << marker << std::endl;
			std::cout << "Se han procesado " << i+14 << " characteres antes del marker." << std::endl;
			break;
		}
		
		marker = "";
	}
	return 0;
}
	
bool checkMarker(std::string sequence) {

	if(sequence[0] == sequence[1] || sequence[0] == sequence[2] || sequence[0] == sequence[3] ||
		sequence[0] == sequence[4] || sequence[0] == sequence[5] || sequence[0] == sequence[6] ||
		sequence[0] == sequence[7] || sequence[0] == sequence[8] || sequence[0] == sequence[9] ||
		sequence[0] == sequence[10] || sequence[0] == sequence[11] || sequence[0] == sequence[12] ||
		sequence[0] == sequence[13] || sequence[0] == sequence[14]) {
		return false;
	}
	else if(sequence[1] == sequence[2] || sequence[1] == sequence[3] ||
		sequence[1] == sequence[4] || sequence[1] == sequence[5] || sequence[1] == sequence[6] ||
		sequence[1] == sequence[7] || sequence[1] == sequence[8] || sequence[1] == sequence[9] ||
		sequence[1] == sequence[10] || sequence[1] == sequence[11] || sequence[1] == sequence[12] ||
		sequence[1] == sequence[13] || sequence[1] == sequence[14])  {
		return false;
	}
	else if(sequence[2] == sequence[3] ||
		sequence[2] == sequence[4] || sequence[2] == sequence[5] || sequence[2] == sequence[6] ||
		sequence[2] == sequence[7] || sequence[2] == sequence[8] || sequence[2] == sequence[9] ||
		sequence[2] == sequence[10] || sequence[2] == sequence[11] || sequence[2] == sequence[12] ||
		sequence[2] == sequence[13] || sequence[2] == sequence[14]) {
		return false;
	}
	else if(sequence[3] == sequence[4] || sequence[3] == sequence[5] || sequence[3] == sequence[6] ||
		sequence[3] == sequence[7] || sequence[3] == sequence[8] || sequence[3] == sequence[9] ||
		sequence[3] == sequence[10] || sequence[3] == sequence[11] || sequence[3] == sequence[12] ||
		sequence[3] == sequence[13] || sequence[3] == sequence[14]) {
		return false;
	}
	else if(sequence[4] == sequence[5] || sequence[4] == sequence[6] ||
		sequence[4] == sequence[7] || sequence[4] == sequence[8] || sequence[4] == sequence[9] ||
		sequence[4] == sequence[10] || sequence[4] == sequence[11] || sequence[4] == sequence[12] ||
		sequence[4] == sequence[13] || sequence[4] == sequence[14]) {
		return false;
	} 
	else if(sequence[5] == sequence[6] ||
		sequence[5] == sequence[7] || sequence[5] == sequence[8] || sequence[5] == sequence[9] ||
		sequence[5] == sequence[10] || sequence[5] == sequence[11] || sequence[5] == sequence[12] ||
		sequence[5] == sequence[13] || sequence[5] == sequence[14]) {
		return false;
	}
	else if(sequence[6] == sequence[7] || sequence[6] == sequence[8] || sequence[6] == sequence[9] ||
		sequence[6] == sequence[10] || sequence[6] == sequence[11] || sequence[6] == sequence[12] ||
		sequence[6] == sequence[13] || sequence[6] == sequence[14]) {
		return false;
	}
	else if(sequence[7] == sequence[8] || sequence[7] == sequence[9] ||
		sequence[7] == sequence[10] || sequence[7] == sequence[11] || sequence[7] == sequence[12] ||
		sequence[7] == sequence[13] || sequence[7] == sequence[14]) {
		return false;
	}
	else if(sequence[8] == sequence[9] ||
		sequence[8] == sequence[10] || sequence[8] == sequence[11] || sequence[8] == sequence[12] ||
		sequence[8] == sequence[13] || sequence[8] == sequence[14]) {
		return false;
	}
	else if(sequence[9] == sequence[10] || sequence[9] == sequence[11] || sequence[9] == sequence[12] ||
		sequence[9] == sequence[13] || sequence[9] == sequence[14]) {
		return false;
	}
	else if(sequence[10] == sequence[11] || sequence[10] == sequence[12] ||
		sequence[10] == sequence[13] || sequence[10] == sequence[14]) {
		return false;
	}
	else if(sequence[11] == sequence[12] || sequence[11] == sequence[13] || sequence[11] == sequence[14]) {
		return false;
	}
	else if(sequence[12] == sequence[13] || sequence[12] == sequence[14]) {
		return false;
	}
	else if(sequence[13] == sequence[14]) {
		return false;
	}
	else {
		return true;
	}
}		
