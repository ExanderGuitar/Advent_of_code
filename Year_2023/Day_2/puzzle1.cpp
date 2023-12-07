#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

struct Game {
	int ID {};
	int red {};
	int blue {};
	int green {};
	bool gamely {};

	void printInfo() {
		std::cout << "Game ID: " << ID << '\n';
		std::cout << "Red cubes: " << red << '\n';
		std::cout << "Blue cubes: " << blue << '\n';
		std::cout << "Green cubes: " << green << '\n';
	}

	void gamePossible() {
		if(red < 13 & green < 14 & blue < 15) {
			gamely = true;
		}
		else {
			gamely = false;
		}
	}
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

			size_t readPos {line.find(":") + 2};
			size_t initPos {readPos};
			std::string colorStr {};
			std::string numberStr {};

			for(size_t i = readPos; i < line.size(); i++) {
				if(line[i] == ',' | line[i] == ';') {
					readPos = i;
					colorStr = line.substr(initPos, (readPos - initPos));
					initPos = i + 2;

					if(colorStr.find("red") != std::string::npos) {
						numberStr = colorStr.substr(0, colorStr.find(" "));
						game.red += std::stoi(numberStr);
					}
					else if(colorStr.find("blue") != std::string::npos) {
						numberStr = colorStr.substr(0, colorStr.find(" "));
						game.blue += std::stoi(numberStr);
					}
					else if(colorStr.find("green") != std::string::npos) {
						numberStr = colorStr.substr(0, colorStr.find(" "));
						game.green += std::stoi(numberStr);
					}
				}

				if( i == (line.size() - 1)) {
					readPos = i;
					colorStr = line.substr(initPos, ((readPos + 1) - initPos));

					if(colorStr.find("red") != std::string::npos) {
						numberStr = colorStr.substr(0, colorStr.find(" "));
						game.red += std::stoi(numberStr);
					}
					else if(colorStr.find("blue") != std::string::npos) {
						numberStr = colorStr.substr(0, colorStr.find(" "));
						game.blue += std::stoi(numberStr);
					}
					else if(colorStr.find("green") != std::string::npos) {
						numberStr = colorStr.substr(0, colorStr.find(" "));
						game.green += std::stoi(numberStr);
					}

				}

			}
			
			listGame.push_back(game);
		}
	}

	int sumOfGames {};

	for(auto& game : listGame) {
		game.gamePossible();

		if(game.gamely) {
			sumOfGames += game.ID;
			std::cout << "Id to sum: " << game.ID << '\n';
		}
	}

	std::cout << "The sum of games is: " << sumOfGames << '\n';			
	return 0;
}
