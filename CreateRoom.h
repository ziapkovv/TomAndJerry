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

// ������������ �� ������� ����� � ������
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

	// ��������� �����������
	CreateRoom();
	CreateRoom(string file);
	~CreateRoom();
	CreateRoom(const CreateRoom& other);
	CreateRoom& operator=(const CreateRoom& other);

	// ������� �������

	char** getMyRoom() const; // ����� ��������� ����� ���� ������������ �� ������
	void setChar(int _x, int _y, char c); // ������ ������ �� ������� ������� � ���������
	void printRoom() const; // ������� ������������ �� ������
	RoomInformation getRoomInformation(); // ����� ���������� �� ������

private:

	char** myRoom;

	RoomInformation myRoomInfo;

	void copyRoom(const CreateRoom& other);

};

#endif /* ROOMINFORMATION_H_ */
