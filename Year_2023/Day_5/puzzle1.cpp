#include <iostream>
#include <fstream>
#include <vector>

struct Game {
	int time {};
	int dist {};
};

int main () {
	
	std::ifstream fileIn {"input.txt"};

	if (!fileIn) {
		std::cout << "Error al leer el archivo.\n";
	}

	std::string line {};

	// Get time points
	std::getline(fileIn, line);

	
	std::getline(fileIn, line);
	std::cout << line << '\n';
}
