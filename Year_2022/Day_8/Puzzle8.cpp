//Importacion de bibliotecas
#include <iostream>
#include <fstream>
#include <vector>

//Definición de funciones
void printForest(std::vector<std::vector<int>> &matrix); 
int countEdgesTrees(std::vector<std::vector<int>> &matrix); 
int countTopTrees(std::vector<std::vector<int>> &matrix); 

//Inicio del bucle principal
int main() {
	//Apertura y cargado del archivo
	std::ifstream inputData;
	inputData.open("input.txt");

	if(inputData.fail()) {
		std::cerr << "Error al abrir el archivo." << std::endl;
	}
	else {
		std::cout << "Exito al cargar el archivo." << std::endl;
	}

	//Variables
	std::string rawValue = "";
	int row = 0;
	int column = 0;
	std::vector<std::vector<int>> forest; //Vector de vectores int
	int edgeTrees = 0;
	int visibleTrees = 0;

	//Lee las lineas del archivo
	while(inputData) {		
		std::getline(inputData, rawValue);
		if(rawValue.empty()) {
			break;
		}
		
		std::vector <int> newRow; //Vector temporal int para cargar los enteros antes de incluirlo al vector forest

		for(column = 0; column < rawValue.size(); column++) {
			int number = int(rawValue[column]); //Convierte el cahr a int

			newRow.push_back(number); //Añade los numeros, cada uno es una columna
		}
		forest.push_back(newRow); //Añade la fila a la matriz forest
		row++;
	}

	//Cierra el archivo
	inputData.close();

	edgeTrees = countEdgesTrees(forest);
	
	std::cout << "Los arbos visibles del borde son : " << edgeTrees << std::endl;

	visibleTrees = countTopTrees(forest);

	std::cout << "Los arboles visibles en total son : " << visibleTrees + edgeTrees << std::endl;

	return 0;
}

//Imprime la matriz
void printForest(std::vector<std::vector<int>> &matrix) {
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j];
		}
	std::cout << std::endl;
	}
}

//Cuenta los arboles del borde del bosque
int countEdgesTrees(std::vector<std::vector<int>> &matrix) {
	int topDownTrees = matrix.size() * 2;	
	int leftRightTrees = (matrix[0].size() * 2) - 4;
	return (topDownTrees + leftRightTrees);
}

//Cuenta los arboles visibles desde arriba
int countTopTrees(std::vector<std::vector<int>> &matrix) {
	int treeHeight = 0;
	int otherTreeHeight = 0;
	bool topVisible = true;
	bool bottomVisible = true;
	bool leftVisible = true;
	bool rightVisible = true;
	int totalVisibles = 0;
	int top = 0;
	int bottom = 0;
	int left = 0;
	int right = 0;

	//Selecciona el arbol objetivo
	for(int row = 1; row < matrix.size()-1; row++) {
		for(int column = 1; column < matrix[row].size()-1; column++) {
			treeHeight = matrix[row][column];
			
			//Selecciona el siguiente arbol por encima y comprueba la altura
			for(int i = row-1; i >= 0; i--) {
				otherTreeHeight = matrix[i][column];
				
				if(otherTreeHeight >= treeHeight) {
					topVisible = false;
				}
			}

			//Selecciona el siguiente arbol por debajo y comprueba la altura
			for(int i = row+1; i < matrix.size(); i++) {
				otherTreeHeight = matrix[i][column];

				if(otherTreeHeight >= treeHeight) {
					bottomVisible = false;
				}
			}

			//Selecciona el siguiente arbol por la izquierda y comprueba la altura
			for(int j = column-1; j >= 0; j--) {
				otherTreeHeight = matrix[row][j];

				if(otherTreeHeight >= treeHeight) {
					leftVisible = false;
				}
			}
			
			//Selecciona el siguiente arbol por la derecha y comprueba la altura
			for(int j = column+1; j < matrix[row].size(); j++) {
				otherTreeHeight = matrix[row][j];

				if(otherTreeHeight >= treeHeight) {
					rightVisible = false;
				}
			}
		//Si el arbol es visible, sumar
		if (topVisible) {
			top++;	
		}
		else if (bottomVisible) {
			bottom++;
		}
		else if (leftVisible) {
			left++;
		}
		else if (rightVisible) {
			right++;
		}
	}
	topVisible = true;
	bottomVisible = true;
	leftVisible = true;
	rightVisible = true;
	}
	std::cout << "Arriba: " << top << " Abajo: " << bottom << " Derecha: " << right << " Izquierda: " << left << std::endl;
	totalVisibles = top + bottom + left + right;
	return totalVisibles;
}
