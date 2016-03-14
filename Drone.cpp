/*
 * Drone.cpp
 *
 *  Created on: Dec 28, 2015
 *      Author: zyapkov
 */

#include "Drone.h"
#include <iostream>

using namespace std;

// �����������
Drone::Drone(const CreateRoom& room) {

	myRoom = room;

	position = 0;
	path = "";

	findPath(myRoom.getRoomInformation().positionTom.x,
			myRoom.getRoomInformation().positionTom.y, 'T');

	findShortestPaths();
	shortestPathsTree.addPaths(shortestPaths, shortestPaths.size());
}

void Drone::printPathsTree() const {

	shortestPathsTree.print();
}

// ������� �� ��������� ������ ������ � ���-���� �������
void Drone::printAllShortestPaths() {

	int n = 0;

	for (list<string>::const_iterator it = shortestPaths.begin();
			it != shortestPaths.end(); it++) {

		n++;
		cout << "��� " << n << ": ";
		Position* current = getPath(*it);
		int i = 0;
		int max = getPathCommands(*it).size() + 1;
		while (i < max) {
			current[i].printPosition();
			if (i != max - 1) {
				cout << "->";
			}
			i++;
		}
		cout << endl;
	}
}

// ������ ������ ������ � ���-���� ������� � ��������� ��� �������� paths
// � ������� ���� ������ � ��������� ��� ���-������ ������ shortestPaths
void Drone::findShortestPaths() {

	shortestLength = getPathCommands(*allPaths.begin()).size();

	for (list<string>::const_iterator it = allPaths.begin();
			it != allPaths.end(); it++) {
		if (getPathCommands(*it).size() < shortestLength) {
			shortestLength = getPathCommands(*it).size();
		}
	}

	for (list<string>::const_iterator it = allPaths.begin();
			it != allPaths.end(); it++) {
		if (getPathCommands(*it).size() == shortestLength) {
			shortestPaths.push_back(*it);
		}
	}
}

// ������� ��������� �� ������ ���-������ ������,
// ����� ��� ������ �� ������ � ����� ��

void Drone::printALLShortestCommands() {

	int i = 0;

	for (list<string>::const_iterator it = shortestPaths.begin();
			it != shortestPaths.end(); it++) {
		i++;
		cout << "������� �� ��� " << i << ": " << getPathCommands(*it) << endl;
	}
}

// ����� ���-������ ������� �� ����
int Drone::getShortestLength() const {

	return shortestLength;

}

// ����� ������������ ������� ��� �� ���� _path
int Drone::getPathAmauntOfPaint(string _path) const {

	int currentAmaunt = 0;

	for (unsigned int i = 0; i < _path.size(); i++) {
		if (_path.at(i) == 'P') {
			currentAmaunt++;
		}
	}

	return currentAmaunt;

}

// ������� ������������ ������� ��� �� ����� �� ��������
void Drone::printAmauntOfPaint() const {

	int i = 0;

	for (list<string>::const_iterator it = allPaths.begin();
			it != allPaths.end(); it++) {
		i++;

		cout << "������� ��� �� ��� " << i << "(" << *it << ") = "
				<< getPathAmauntOfPaint(*it) << endl;
	}
}

// ����� ���� ����� �� ���� _path
int Drone::getPathTurns(string _path) const {

	int turns = 0;

	string tempPath = getPathCommands(_path);

	for (unsigned int i = 0; i < tempPath.size() - 1; i++) {
		if (tempPath.at(i) != tempPath.at(i + 1)) {
			turns++;
		}
	}

	return turns;

}

// ������� ���� ����� �� ������ ������
void Drone::printPathsTurns() const {

	int i = 0;

	for (list<string>::const_iterator it = allPaths.begin();
			it != allPaths.end(); it++) {
		i++;
		cout << "���� �� ������� �� ��� " << i << "(" << *it << ") = "
				<< getPathTurns(*it) << endl;
	}

}

void Drone::maxPaintPath() {

	int maxPaint = 0;
	list<string> temp;

	for (list<string>::const_iterator it = allPaths.begin();
			it != allPaths.end(); it++) {
		if (maxPaint < getPathAmauntOfPaint(*it)) {

			maxPaint = getPathAmauntOfPaint(*it);
			temp.clear();
			temp.push_back(*it);

		} else {
			if (maxPaint == getPathAmauntOfPaint(*it)) {

				temp.push_back(*it);

			}
		}
	}

	string result = temp.front();

	for (list<string>::const_iterator it = temp.begin(); *it != temp.back();
			it++) {
		if (getPathTurns(*it) < getPathTurns(result)) {
			result = *it;
		}
	}

	cout << "����� ,�� ����� �� ������� ���-����� ���\n";
	cout << "� ������������� � � �������� ���-����� �����: ";
	Position* maxPaintPath = getPath(result);

	int i = 0;
	int max = getPathCommands(result).size() + 1;
	while (i < max) {
		maxPaintPath[i].printPosition();
		if (i != max - 1) {
			cout << "->";
		}
		i++;
	}

	cout << endl;

}

// ����� ��������� ����� ��� ������ �� ������ � ����� �� �� ���� _path, ����� �������� �� P
string Drone::getPathCommands(string _path) const {

	string tempPath = "";

	for (unsigned int i = 0; i < _path.size(); i++) {
		if (_path.at(i) != 'P') {
			tempPath = tempPath + _path.at(i);
		}
	}

	return tempPath;

}

// ����� �� ������� ����� �� ����� � ���������� �� ��������
void Drone::chooseLeaf(unsigned int leaf) const {

	if (leaf <= 0 || leaf > shortestPaths.size()) {
		cout << "Error! Invalid number of leaf!" << endl;
		exit(1);
	} else {

		unsigned int i = 0;

		for (list<string>::const_iterator it = shortestPaths.begin();
				it != shortestPaths.end(); it++) {

			i++;

			if (leaf == i) {
				cout << "���������, ����� ������ �� �� ������� � �����:"
						<< getPathCommands(*it) << endl;
				cout << "��������� �� ����: " << shortestLength << endl;
				cout << "������������ ������� ��� �� ����: "
						<< getPathAmauntOfPaint(*it) << endl;
				cout << "���� ����� �� ����: " << getPathTurns(*it) << endl;

				break;
			}
		}
	}
}

// �������, ������� ������ ������ �� ��� �� �����
void Drone::findPath(int row, int col, char direction) {

	int paint = 0;

	if ((row < 0 || col < 0)
			|| (col >= myRoom.getRoomInformation().roomSize.x
					|| row >= myRoom.getRoomInformation().roomSize.y)) {
		return;

	}

	if (direction != 'T') {
		path += direction;
		position++;
	}

	if (myRoom.getMyRoom()[row][col] == 'J') {
		allPaths.push_back(path);
	}

	if (myRoom.getMyRoom()[row][col] == '*'
			|| myRoom.getMyRoom()[row][col] == 'P'
			|| myRoom.getMyRoom()[row][col] == 'T') {

		if (myRoom.getMyRoom()[row][col] == 'P') {
			paint++;
			path += 'P';
			position++;
		}

		myRoom.setChar(row, col, 's');

		findPath(row, col - 1, 'L'); // ������
		findPath(row, col + 1, 'R'); // �������
		findPath(row - 1, col, 'F'); // ������
		findPath(row + 1, col, 'B'); // ������

		if (row == myRoom.getRoomInformation().positionTom.x
				&& col == myRoom.getRoomInformation().positionTom.y) {
			myRoom.setChar(row, col, 'T');
		} else {

			if (paint == 1) {
				myRoom.setChar(row, col, 'P');
			} else {

				myRoom.setChar(row, col, '*');
			}
		}

	}
	position = position - 1 - paint;
	path = path.substr(0, position);
}

void Drone::twoDronesWorks() {

	list<string> sortPaths = allPaths;

	for (list<string>::iterator it = sortPaths.begin(); *it != sortPaths.back();
			it++) {
		for (list<string>::iterator next = it; next != sortPaths.end();
				next++) {

			int secondCommands = getPathCommands(*next).size();
			int firstCommands = getPathCommands(*it).size();

			if ((secondCommands < firstCommands)
					|| (secondCommands == firstCommands
							&& getPathAmauntOfPaint(*next)
									> getPathAmauntOfPaint(*it))) {

				string temp = *next;
				*next = *it;
				*it = temp;

			}
		}
	}

	for (list<string>::iterator it = sortPaths.begin(); *it != sortPaths.back();
			it++) {

		list<string>::iterator next = it;
		++next;

		while (getPathCommands(*next).size() == getPathCommands(*it).size()) {

			int firstLength = getPathCommands(*it).size();
			int secondLength = getPathCommands(*next).size();

			Position* first = getPath(*it);
			Position* second = getPath(*next);

			if (firstLength == secondLength
					&& areInSamePosition(first, second, firstLength) == false) {
				cout << "����� 2:" << endl;
				cout << "��� �� ���� 1: " << getPathCommands(*it) << endl;
				cout << "��� �� ���� 2: " << getPathCommands(*next) << endl;
				return;
			}
			++next;
		}
	}

	cout << "����� 2: ����� ����� �� ����� �� �� �����������";
	cout << ", ���� �� �� ������� ������." << endl;
}

bool Drone::areInSamePosition(Position* firstPath, Position* secondPath,
		int length) const {

	int i = 1;

	while (i < length - 1) {

		if ((firstPath[i].x == secondPath[i].x)
				&& (firstPath[i].y == secondPath[i].y)) {
			return true;
		}

		i++;
	}

	return false;
}

Position* Drone::getPath(string _path) {

	int size = getPathCommands(_path).size() + 1;
	int x = myRoom.getRoomInformation().positionTom.x;
	int y = myRoom.getRoomInformation().positionTom.y;

	Position* temp = new Position[size];
	temp[0].x = x;
	temp[0].y = y;

	int i = 1;

	while (!_path.empty()) {

		char c = _path.at(0);
		_path = _path.substr(1);

		switch (c) {
		case 'F':
			x--;
			temp[i].x = x;
			temp[i].y = y;
			i++;
			break;
		case 'R':
			y++;
			temp[i].x = x;
			temp[i].y = y;
			i++;
			break;
		case 'L':
			y--;
			temp[i].x = x;
			temp[i].y = y;
			i++;
			break;
		case 'B':
			x++;
			temp[i].x = x;
			temp[i].y = y;
			i++;
			break;
		}
	}

	return temp;
}
