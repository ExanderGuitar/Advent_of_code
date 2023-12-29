//Libraries import
#import <iostream>
#import <fstream>
#import <vector>

struct Rope {
	int x = 0;
	int y = 0;
	std::vector <int> oldX;
	std::vector <int> oldY;

	void addOldPosition() {
		oldX.push_back(x);
		oldY.push_back(y);
	}

	void printOldCoord() {
		for(int i = 0; i < oldX.size(); i++) {
			std::cout << oldX[i] << ", " << oldY[i] << std::endl;
		}
	}

	void followRopes(Rope &other) {
		int difX = 0;
		int difY = 0;

		difX = other.x - x;
		if (difX < 0) {
			difX *= -1;
		}
		difY = other.y - y;
		if (difY < 0) {
			difY *= -1;
		}

		if(difX >= 2) {
			if(other.x < x) {
				x = other.x + 1;
			}
			else {
				x = other.x - 1;
			}
			y = other.y;
		}
		
		if(difY >= 2) {
			if(other.y < y) {
				y = other.y + 1;
			}
			else {
				y = other.y - 1;
			}
			x = other.x;
		}	
	}
};

//Function declaration
void addKnotsToTail(std::vector<Rope> &t, int knots); 
void dumpInputToVector(std::string fileName, std::vector<std::string> &array);
void decodeData(std::vector<std::string> &input, std::vector<char> &dir, std::vector<int> &num, bool condition); 
void moveRope(std::vector<char> &dir, std::vector<int> &num, Rope &h, std::vector<Rope> &t); 
int countOcurrences(Rope &t);
 
int main() {
	//Variables
	std::vector<std::string> movements;
	std::vector<char> direction;
	std::vector<int> times;
	
	Rope head;
	std::vector<Rope> tail;	
	
	int ocurrences = 0;

	
	dumpInputToVector("input.txt", movements);
	//dumpInputToVector("example.txt", movements);
	decodeData(movements, direction, times, false); 

	addKnotsToTail(tail, 9); 

	moveRope(direction, times, head, tail); 

	for(int i = 0; i < tail.size(); i++) {
		ocurrences += countOcurrences(tail[i]);
	}
	
	std::cout << "Positions visited by the tail: " << ocurrences << std::endl;
	return 0;
}

void addKnotsToTail(std::vector<Rope> &t, int knots) {
	Rope knot;
	for(int i = 0; i < knots; i++) {
		t.push_back(knot);
	}
}

int countOcurrences(Rope &t) {
	std::vector<int> xPos;
	std::vector<int> yPos;
	int x = 0;
	int y = 0;
	bool exist = false;

	for(int i = 0; i < t.oldX.size(); i++) {
		x = t.oldX[i];
		y = t.oldY[i];

		for(int j = 0; j < xPos.size(); j++) {
			if(xPos[j] == x && yPos[j] == y) {
				exist = true;	
			}
		}

		if(exist != true) {
			xPos.push_back(x);
			yPos.push_back(y);
		}
		exist = false;
	}

	return xPos.size();
}
void dumpInputToVector(std::string fileName, std::vector<std::string> &array) {
	std::ifstream inputData;
	inputData.open(fileName);

	if(inputData.fail()) {
		std::cerr << "Error al cargar el archivo." << std::endl;
	}

	std::string rawValue = " ";

	while(inputData) {
		std::getline(inputData, rawValue);
		if(rawValue.empty()) {
			break;
		}

		array.push_back(rawValue);
	}

	inputData.close();
} 

void decodeData(std::vector<std::string> &input, std::vector<char> &dir, std::vector<int> &num, bool condition) {
	for(int i = 0; i < input.size(); i++) {
		dir.push_back(input[i][0]);
		
		std::string number = input[i].substr(input[i].find(" "));
		num.push_back(stoi(number));
	}			

	if(condition) {
		for(int i = 0; i < dir.size(); i++) {
			std::cout << dir[i];
			std::cout << num[i];
		}
	}
}

void moveRope(std::vector<char> &dir, std::vector<int> &num, Rope &h, std::vector<Rope> &t) {
	for(int i = 0; i < dir.size(); i++) {
		switch (dir[i]) {
			case 'U':
				for(int j = 0; j < num[i]; j++) {
					h.y += 1;
					h.addOldPosition();
					for(int k = 0; k < t.size(); k++) {
						if(k == 0) {
							t[k].followRopes(h);	
							t[k].addOldPosition();
						}
						else {
							t[k].followRopes(t[k-1]);
							t[k].addOldPosition();
						}
					}
				}
				break;
			case 'D':
				for(int j = 0; j < num[i]; j++) {
					h.y -= 1;
					h.addOldPosition();
					for(int k = 0; k < t.size(); k++) {
						if(k == 0) {
							t[k].followRopes(h);	
							t[k].addOldPosition();
						}
						else {
							t[k].followRopes(t[k-1]);
							t[k].addOldPosition();
						}
					}
				}
				break;
			case 'L':
				for(int j = 0; j < num[i]; j++) {
					h.x -= 1;
					h.addOldPosition();
					for(int k = 0; k < t.size(); k++) {
						if(k == 0) {
							t[k].followRopes(h);	
							t[k].addOldPosition();
						}
						else {
							t[k].followRopes(t[k-1]);
							t[k].addOldPosition();
						}
					}
				}
				break;
			case 'R':
				for(int j = 0; j < num[i]; j++) {
					h.x += 1;
					h.addOldPosition();
					for(int k = 0; k < t.size(); k++) {
						if(k == 0) {
							t[k].followRopes(h);	
							t[k].addOldPosition();
						}
						else {
							t[k].followRopes(t[k-1]);
							t[k].addOldPosition();
						}
					}
				}
				break;
			defaul:
				std::cerr << "Algo ha salido mal." << std::endl;
				break;
		}
	}
}
