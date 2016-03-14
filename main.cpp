/*
 * main.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: zyapkov
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "CreateRoom.h"
#include "Drone.h"
#include "Tree.h"

using namespace std;

int main() {

	CreateRoom myRoom("example.txt");

	myRoom.printRoom();

	Drone myDrone(myRoom);

	cout << "1) ����� � ����� ���-����� ��� �� ��� �� �����?" << endl;
	cout << "�������: " << myDrone.getShortestLength() << endl << endl;

	cout << "2) ��� �� ������ ���-���� ������ �� ��� �� �����?" << endl;
	myDrone.printAllShortestPaths();
	cout << endl;

	cout << "3) ����� ��� �� ������ �� ����� �� ��������?" << endl;
	myDrone.printAmauntOfPaint();
	cout << endl;

	cout << "4) ����� ����� �� ������� �� ����� �� ��������?" << endl;
	myDrone.printPathsTurns();
	cout << endl;

	cout << "5) ����� ������� �� ������ � ����� ?" << endl;
	myDrone.printALLShortestCommands();
	cout << endl;

	cout << "Tree of commands:" << endl;
	myDrone.printPathsTree();

//	int leafNumber;
//
//	cout<<"Enter leaf number: ";
//	cin>>leafNumber;
//	myDrone.chooseLeaf(leafNumber);

//	myDrone.printAmauntOfPaint();

// ����� 1
	cout << "����� 1:" << endl;
	myDrone.maxPaintPath();

// ����� 2
	myDrone.twoDronesWorks();

	cout << endl << "finished" << endl;

	return 0;
}

