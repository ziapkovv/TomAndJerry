/*
 * RoomInformation.h
 *
 *  Created on: Dec 26, 2015
 *      Author: zyapkov
 */

#ifndef ROOMINFORMATION_H_
#define ROOMINFORMATION_H_

#include <iostream>
using namespace std;

// координатите на някакъв обект в стаята
struct Position {

	int x;
	int y;

	void printPosition() const {
		cout << "[" << x << ", " << y << "]";
	}
};

struct RoomInformation {

	Position roomSize;
	Position positionTom;
	Position positionJerry;

	void print() {
		roomSize.printPosition();
		positionJerry.printPosition();
		positionTom.printPosition();
	}
};

class CreateRoom {

public:

	// канонично представяне
	CreateRoom();
	CreateRoom(string file);
	~CreateRoom();
	CreateRoom(const CreateRoom& other);
	CreateRoom& operator=(const CreateRoom& other);

	// основни функции

	char** getMyRoom() const; // връща матрицата която пази информацията за стаята
	void setChar(int _x, int _y, char c); // задава символ на някаква позиция в матрицата
	void printRoom() const; // извежда информацията за стаята
	RoomInformation getRoomInformation(); // връща информация за стаята

private:

	char** myRoom;

	RoomInformation myRoomInfo;

	void copyRoom(const CreateRoom& other);

};

#endif /* ROOMINFORMATION_H_ */
