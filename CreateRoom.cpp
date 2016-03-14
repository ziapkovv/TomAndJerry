/*
 * CreateRoom.cpp
 *
 *  Created on: Dec 27, 2015
 *      Author: zyapkov
 */

#include "CreateRoom.h"
#include <fstream>

CreateRoom::CreateRoom() {

	myRoom = NULL;

}

CreateRoom::CreateRoom(string file) {
	// n - височина, m - ширина, k - брой мебели, l - брой места за разливане на боя, x,y- временни координати
	int n, m, k, l, x, y;
	string line;

	ifstream fileReader(file.data());

	if (fileReader.is_open()) {

		// четем първия ред, тоест размерността на стаята
		fileReader >> n >> m;

		myRoomInfo.roomSize.y = n; // записваме височината
		myRoomInfo.roomSize.x = m; // записваме ширината

		// заделяме памет за масива в който ще пазим стата
		myRoom = new char*[n];
		for (int i = 0; i < n; i++) {
			myRoom[i] = new char[m];
		}

		// инициализираме всяка позиция на нашия масив с *, което означава че
		// на тази позиция нямаме нищо
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				myRoom[i][j] = '*';
			}
		}

		// четем от файла и записваме в масива координатите на Джери
		fileReader >> x >> y;
		myRoom[x][y] = 'J';

		// записваме позицията на Джери
		myRoomInfo.positionJerry.x = x;
		myRoomInfo.positionJerry.y = y;

		// четем от файла и записваме в масива координатите на Том
		fileReader >> x >> y;
		myRoom[x][y] = 'T';

		// записваме позицията на Том
		myRoomInfo.positionTom.x = x;
		myRoomInfo.positionTom.y = y;

		// записваме в k и l броя мебели и
		// броя места за разливане на боя съответно
		fileReader >> k >> l;

		// Четене на описанията на мебелите
		for (int i = 0; i < k; i++) {
			int countRows = -1;
			fileReader >> x >> y; // горните леви кординати на мебелта
			getline(fileReader, line);
			while (line != "===") {
				for (unsigned int j = 0; j < line.size(); j++) {
					if (line[j] == '1') {
						myRoom[x + countRows][y + j] = '#';
					}
				}
				getline(fileReader, line);
				countRows++;
			}
		}
		for (int i = 0; i < l; i++) {
			fileReader >> x >> y;
			myRoom[x][y] = 'P';
		}

		fileReader.close();

	} else {
		cout << "Error: Cannot open file." << endl;
	}
}

CreateRoom::~CreateRoom() {

	delete[] myRoom;

}

CreateRoom::CreateRoom(const CreateRoom& other) {

	copyRoom(other);

}

CreateRoom& CreateRoom::operator =(const CreateRoom& other) {

	if (this != &other) {
		this->~CreateRoom();
		this->copyRoom(other);
	}

	return *this;
}

// извежда матрицата от символи, която пази информацията за стаята
void CreateRoom::printRoom() const {

	for (int i = 0; i < myRoomInfo.roomSize.y; i++) {
		for (int j = 0; j < myRoomInfo.roomSize.x; j++) {
			cout << myRoom[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// връща матризата, съдържаща информацията за стаята
char** CreateRoom::getMyRoom() const {

	char** temp = new char*[myRoomInfo.roomSize.y];

	for (int i = 0; i < myRoomInfo.roomSize.y; i++) {
		temp[i] = new char[myRoomInfo.roomSize.x];
	}

	for (int i = 0; i < myRoomInfo.roomSize.y; i++) {
		for (int j = 0; j < myRoomInfo.roomSize.x; j++) {

			temp[i][j] = myRoom[i][j];

		}
	}

	return temp;

}

// връща структурата RoomInformation, пазеща данните за стаята
RoomInformation CreateRoom::getRoomInformation() {

	return myRoomInfo;

}

// задава символа c върху някаква точка с координати (_x,_y) върху матрицата
// съдържаща информацията за стаята
void CreateRoom::setChar(int _x, int _y, char c) {

	myRoom[_x][_y] = c;

}

// помощтна функция за копиране на стая
void CreateRoom::copyRoom(const CreateRoom& other) {

	myRoomInfo = other.myRoomInfo;

	myRoom = new char*[myRoomInfo.roomSize.y];

	for (int i = 0; i < myRoomInfo.roomSize.y; i++) {
		myRoom[i] = new char[myRoomInfo.roomSize.x];
	}

	for (int i = 0; i < myRoomInfo.roomSize.y; i++) {
		for (int j = 0; j < myRoomInfo.roomSize.x; j++) {
			myRoom[i][j] = other.myRoom[i][j];
		}
	}
}

