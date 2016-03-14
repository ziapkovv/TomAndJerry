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
	// n - ��������, m - ������, k - ���� ������, l - ���� ����� �� ��������� �� ���, x,y- �������� ����������
	int n, m, k, l, x, y;
	string line;

	ifstream fileReader(file.data());

	if (fileReader.is_open()) {

		// ����� ������ ���, ����� ������������ �� ������
		fileReader >> n >> m;

		myRoomInfo.roomSize.y = n; // ��������� ����������
		myRoomInfo.roomSize.x = m; // ��������� ��������

		// �������� ����� �� ������ � ����� �� ����� �����
		myRoom = new char*[n];
		for (int i = 0; i < n; i++) {
			myRoom[i] = new char[m];
		}

		// �������������� ����� ������� �� ����� ����� � *, ����� �������� ��
		// �� ���� ������� ������ ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				myRoom[i][j] = '*';
			}
		}

		// ����� �� ����� � ��������� � ������ ������������ �� �����
		fileReader >> x >> y;
		myRoom[x][y] = 'J';

		// ��������� ��������� �� �����
		myRoomInfo.positionJerry.x = x;
		myRoomInfo.positionJerry.y = y;

		// ����� �� ����� � ��������� � ������ ������������ �� ���
		fileReader >> x >> y;
		myRoom[x][y] = 'T';

		// ��������� ��������� �� ���
		myRoomInfo.positionTom.x = x;
		myRoomInfo.positionTom.y = y;

		// ��������� � k � l ���� ������ �
		// ���� ����� �� ��������� �� ��� ���������
		fileReader >> k >> l;

		// ������ �� ���������� �� ��������
		for (int i = 0; i < k; i++) {
			int countRows = -1;
			fileReader >> x >> y; // ������� ���� ��������� �� �������
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

// ������� ��������� �� �������, ����� ���� ������������ �� ������
void CreateRoom::printRoom() const {

	for (int i = 0; i < myRoomInfo.roomSize.y; i++) {
		for (int j = 0; j < myRoomInfo.roomSize.x; j++) {
			cout << myRoom[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// ����� ���������, ��������� ������������ �� ������
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

// ����� ����������� RoomInformation, ������ ������� �� ������
RoomInformation CreateRoom::getRoomInformation() {

	return myRoomInfo;

}

// ������ ������� c ����� ������� ����� � ���������� (_x,_y) ����� ���������
// ��������� ������������ �� ������
void CreateRoom::setChar(int _x, int _y, char c) {

	myRoom[_x][_y] = c;

}

// �������� ������� �� �������� �� ����
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

