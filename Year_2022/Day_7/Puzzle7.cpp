//Librerias
#include <iostream>
#include <fstream>
#include <vector>

//Definiciones de estructuras
struct Folder {
	std::string name
	std::vector <Folder> folders;
	std::vector <std::string> files;;
};

//Definiciones de funciones
void commandLine(std::string command, std::vector <std::string> &route); 
void changeDirectory(std::vector <std::string> &route, std::string directory); 
void updateRoute(std::vector <std::string> &route, std::string directory); 
void printRoute(std::vector <std::string> route); 
 
//Entrada del programa
int main() {
	//Carga del archivo
	std::ifstream inputData;
	inputData.open("input.txt");

	if(inputData.fail()) {
		std::cerr << "Error al cargar el archivo" << std::endl;
	}
	else {
		std::cout << "Archivo cargado con exito." << std::endl;
	}

	//Variables
	std::string rawValue;
	std::vector <std::string> systemRoute;

	Carpeta raiz;

	systemRoute.push_back("/");

	while(inputData) {
		std::getline(inputData, rawValue);

		if(rawValue.find("$") != -1) {
			commandLine(rawValue, systemRoute);
		}
	}

	printRoute(systemRoute);
	inputData.close();
	return 0;
}

//Recibe los comandos y los gestiona
void commandLine(std::string command, std::vector <std::string> &route) {
	if(command.find("$ ls") != -1) {
		std::cout << "Imprimir directorio" << std::endl;
	}
	else if(command.find("cd") != -1) {
		std::cout << "Cambiar directorio" << std::endl;
		//Busca la posición donde empieza el nombre del directorio
		int firstSpace = command.find(" ") + 1;
		int secondSpace = command.find(" ", firstSpace);
		//Genera un substring solamente con el nombre del directorio
		std::string dir = command.substr(secondSpace + 1);
		//Llamada a la función
		changeDirectory(route, dir);
	}
}


void changeDirectory(std::vector <std::string> &route, std::string directory) {
	if (directory != "..") {
		std::string currentDir = route[route.back()-1];	
		
	updateRoute(route, directory);
}

void updateRoute(std::vector <std::string> &route, std::string directory) {
	if(directory == "..") {
		route.pop_back();
		route.pop_back();
	}
	else {
		if(directory != "/") {
			route.push_back(directory);
			route.push_back("/");
		}
		else {
			route.clear();
			route.push_back("/");
		}
	}	
}

void printRoute(std::vector <std::string> route) {
	std::cout << "Ruta: ";
	for(int i = 0; i < route.size(); i++) {
		std::cout << route[i];
	}
	std::cout << std::endl;
}
