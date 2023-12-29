#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* A = 1	- 1 = X
	B = 2 - 2 = Y
	C = 3 - 3 = Z

	WIN	= 6
	DRAW	= 3
	LOSE	= 0
*/

int answerPoint(char ans);
int matchPoint(char say, char ans); 
int newAnswerPoint(char say, char ans);
int newMatchPoint(char ans); 
 
int main () {
	std::ifstream inputData;
	inputData.open("input.txt");

	if(inputData.fail()) {
		std::cerr << "Error al cargar el archivo" << std::endl;
	}
	else {
		std::cerr << "Archivo cargado con exito" << std::endl;
	}
		
	std::string rawValue = "";
	char call;
	char answer;;

	std::vector <int> callCollection;
	std::vector <int> answerCollection;

	int answerPoints = 0;
	int matchPoints = 0;
	int totalPoints = 0;

	while(inputData) {
		std::getline(inputData, rawValue);
		std::cout << rawValue << std::endl;
		
		call = rawValue[0];
		answer = rawValue[2];

		//answerPoints = answerPoint(answer);		
		//matchPoints = matchPoint(call, answer); 

		answerPoints = newAnswerPoint(call, answer);
		matchPoints = newMatchPoint(answer); 

		totalPoints += (answerPoints + matchPoints);
		std::cout << "Puntuacion: " << totalPoints << std::endl;
	}

	std::cout << "Los puntos totales son: " << totalPoints << std::endl;

	return 0;
}

int answerPoint(char ans) {
	int toReturn;

	switch(ans) {
		case 'X':
			toReturn = 1;
			break;
		case 'Y':
			toReturn = 2;
			break;
		case 'Z':
			toReturn = 3;
			break;
		default:
			toReturn = 0;
			break;
	}

	std::cout << "Puntos por seleccion: " << toReturn << std::endl;
	return toReturn;
}

int matchPoint(char say, char ans) {
	int toReturn;

	if (say == 'A') {
		switch (ans) {
			case 'X':
				toReturn = 3;
				break;
			case 'Y':
				toReturn = 6;
				break;
			case 'Z':
				toReturn = 0;
				break;
		}
	}
	else if (say == 'B') {
		switch (ans) {
			case 'X':
				toReturn = 0;
				break;
			case 'Y':
				toReturn = 3;
				break;
			case 'Z':
				toReturn = 6;
				break;
		}
	}
	else if (say == 'C') {
		switch (ans) {
			case 'X':
				toReturn = 6;
				break;
			case 'Y':
				toReturn = 0;
				break;
			case 'Z':
				toReturn = 3;
				break;
		}
	}
	else {
		toReturn = 0;
	}

	std::cout << "Puntos por partida: " << toReturn << std::endl;
	return toReturn;
}

int newAnswerPoint(char say, char ans) {
	int toReturn;

	if (say == 'A') {
		switch (ans) {
			case 'X':
				toReturn = 3;
				break;
			case 'Y':
				toReturn = 1;
				break;
			case 'Z':
				toReturn = 2;
				break;
		}
	}
	else if (say == 'B') {
		switch (ans) {
			case 'X':
				toReturn = 1;
				break;
			case 'Y':
				toReturn = 2;
				break;
			case 'Z':
				toReturn = 3;
				break;
		}
	}
	else if (say == 'C') {
		switch (ans) {
			case 'X':
				toReturn = 2;
				break;
			case 'Y':
				toReturn = 3;
				break;
			case 'Z':
				toReturn = 1;
				break;
		}
	}
	else {
		toReturn = 0;
	}


	std::cout << "Puntos por seleccion: " << toReturn << std::endl;
	return toReturn;
}


int newMatchPoint(char ans) {
	int toReturn;

	switch (ans) {
		case 'X':
			toReturn = 0;
			break;
		case 'Y':
			toReturn = 3;
			break;
		case 'Z':
			toReturn = 6;
			break;
		default:
			toReturn = 0;
			break;
	}
	std::cout << "Puntos por partida: " << toReturn << std::endl;
	return toReturn;
}
