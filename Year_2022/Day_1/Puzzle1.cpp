#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

	std::ifstream inputData;
	inputData.open("input.txt");

	if (inputData.fail()) {
		std::cerr << "Error al abrir el archivo" << std::endl;
	}

	std::string value = "0";
	int number = 0;
	int sumCalories = 0;
	std::vector <int> sumCollection;

	int firstValue = 0;
	int secondValue = 0;
	int thirdValue = 0;

	while (inputData) {	
		
		std::getline(inputData, value);
		std::cout << value << std::endl;

		if (value == "") {
			sumCollection.push_back(sumCalories);
			std::cout << "La suma es: " << sumCalories << std::endl;
			sumCalories = 0;
		}
		else {
			number = stoi(value);
			sumCalories += number;
		}
	}

	inputData.close();

	/*for (int i = 0; i < sumCollection.size(); i++) {
		if (sumCollection[i] > firstValue) {
			firstValue = sumCollection[i];
		}
		else if (sumCollection[i] < firstValue && sumCollection[i] > secondValue) {
			secondValue = sumCollection[i];
		}
		else if (sumCollection[i] < secondValue && sumCollection[i] > thirdValue) {
			thirdValue = sumCollection[i];
		}
		else {
		}
	}*/

   std::sort(sumCollection.begin(), sumCollection.end());		
	firstValue = sumCollection[sumCollection.size() - 1];
	secondValue = sumCollection[sumCollection.size() - 2];
	thirdValue = sumCollection[sumCollection.size() - 3];

	std::cout << "La mochila mas calorica tiene " << firstValue << " calorias." << std::endl;
	std::cout << std::endl;
	std::cout << "La primera mochila tiene: " << firstValue << std::endl;
	std::cout << "La segunda mochila tiene: " << secondValue << std::endl;
	std::cout << "La tercera mochila tiene: " << thirdValue << std::endl;
	std::cout << "Entre las tres mas llenas hay " << firstValue + secondValue + thirdValue << " calorias." << std::endl;

	return 0;
}
