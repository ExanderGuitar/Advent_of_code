#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

struct Game {
	std::vector<int> winNumbers {};
	std::vector<int> matchNumbers {};
	
	int points {};
	bool initMatch {false};

	void checkWinners() {
		for(int numb : winNumbers) {
			for(int match : matchNumbers) {
				if(numb == match) {
					if(initMatch) {
						points = points * 2;
					}
					else {
						points = 1;
						initMatch = true;
					}

					break;
				}
			}
		}
	}

	void printPoints() {
		std::cout << "Points: " << points << '\n';
	}
};

int main() {
	std::ifstream fileIn {"input.txt"};

	if(fileIn.bad()) {
		std::cout << "Error al leer el archivo.\n";
	}

	std::string line {};
	std::vector<Game> gameList {};
	int totalPoints {0};

	while(!fileIn.eof()) {
		std::getline(fileIn, line);

		if(!line.empty()) {
			
			Game game {};

			bool winners {true};
			size_t initPos {line.find(":") + 2};
			size_t endPos {};

			if(line[initPos] == ' ') {
				initPos++;
			}
			
			while(endPos < line.size()) {

				while(line[initPos] == ' ') {
					initPos++;
				}

				if(line[initPos] == '|') {
					winners = false;
				}

				endPos = line.find(" ", initPos);

				if(line[initPos] == '|') {
					winners = false;
				}
				else {
					if (winners) {
						game.winNumbers.push_back(std::stoi(line.substr(initPos, (endPos - initPos))));
					}
					else {
						game.matchNumbers.push_back(std::stoi(line.substr(initPos, (endPos - initPos))));	
					}
				}

				initPos = endPos;

			}

			gameList.push_back(game);

			for(Game game : gameList) {
				std::cout << "Win numbers: ";
				for(int numb : game.winNumbers) {
					std::cout << numb << " ";
				}
				std::cout << '\n';

				std::cout << "Match numbers: ";
				for(int numb : game.matchNumbers) {
					std::cout << numb << " ";
				}
				std::cout << '\n';
				std::cout << '\n';
			}

			std::cout << '\n';
		}
	}

	for(Game game : gameList) {
		game.checkWinners();
		game.printPoints();
		totalPoints += game.points;
	}

	std::cout << "La cantidad total de puntos es: " << totalPoints << '\n';
	return 0;
}
