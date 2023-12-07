#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

struct Game {
	int ID {};
};

int main () {

	std::ifstream fileIn {"input.txt"};

	if(fileIn.bad()) {
		std::cout << "Error al abrir el archivo.\n";
	}

	std::vector<Game> listGame {};
	std::string line {};
	
	while(!fileIn.eof()) {
		std::getline(fileIn, line);			

		if(!line.empty()) {
			Game game {};

			std::string gameId = line.substr(5, line.find(":", 5));
			game.ID = std::stoi(gameId);

			std::cout << game.ID << '\n';
		}
	}

	return 0;
}
