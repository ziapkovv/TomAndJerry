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

	cout << "1) Колко е дълъг най-късия път от мен до Джери?" << endl;
	cout << "Дължина: " << myDrone.getShortestLength() << endl << endl;

	cout << "2) Кои са всички най-къси пътища от мен до Джери?" << endl;
	myDrone.printAllShortestPaths();
	cout << endl;

	cout << "3) Колко боя ще разлея по всеки от пътищата?" << endl;
	myDrone.printAmauntOfPaint();
	cout << endl;

	cout << "4) Колко завоя ще направя по всеки от пътищата?" << endl;
	myDrone.printPathsTurns();
	cout << endl;

	cout << "5) Какви команди да въведа в дрона ?" << endl;
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

// бонус 1
	cout << "Бонус 1:" << endl;
	myDrone.maxPaintPath();

// бонус 2
	myDrone.twoDronesWorks();

	cout << endl << "finished" << endl;

	return 0;
}

