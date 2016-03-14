/*
 * Drone.h
 *
 *  Created on: Dec 28, 2015
 *      Author: zyapkov
 */

#include "CreateRoom.h"
#include "Tree.h"
#include <list>
#include <cstring>
#include <cstdlib>

#ifndef DRONE_H_
#define DRONE_H_

class Drone {

public:

	Drone(const CreateRoom& room);

	// принтира дървото на най-късите пътища от Том до Джери !!!
	void printPathsTree() const;

	// принтира всички пътища с най-къса дължина
	// от Том до Джери !!!
	void printAllShortestPaths();

	// извежда всички най-кратки команди от Том до Джери
	void printALLShortestCommands();

	// извежда броя на завоите по всеки от пътищата !!!
	void printPathsTurns() const;

	// извежда количеството боя разлята по всеки от пътищата !!!
	void printAmauntOfPaint() const;

	// връща дължината на най-късия път !!!
	int getShortestLength() const;

	// избирайки пореден номер на листо leaf
	// тази функция извежда командите които Том трябва да въведе в дрона си,
	// дългината на пътя,количеството разлята боя и броя завои за този път
	void chooseLeaf(unsigned int leaf) const;

	// Бонус 1
	// намира пътя по който може да се разлее най-много боя и
	// и при това да има възможно най малък брой завой
	void maxPaintPath();

	// Бонус 2
	// работа с два дрона, намиране на най-бързия начин за
	// достигане до Джери и принтиране на командите, които
	// трябва да се въведат в двата дрона
	void twoDronesWorks();

	bool areInSamePosition(Position* firstPath, Position* secondPath,int length) const;

private:

	Tree shortestPathsTree; // дървото от командите

	CreateRoom myRoom; // пази информация за стаята

	list<string> allPaths; // всички пътища
	list<string> shortestPaths; // всички най-кратки пътища

	string path; // тукущ път
	int position; // колко позиции са минали по време на търсенето на пътя

	unsigned int shortestLength; // пази най-късата дължина на пътя !!!

	// намира всички най-къси пътища от Том до Джери,
	// записва ги в списъка shortestPaths
	void findShortestPaths();

	// намира всички пътища от Том до Джери
	// row е съответно x-координатата на Том
	// col е съответно y-координатата на Том
	// тоест това е стартовата точка
	// direction е текущата посока на дрона
	void findPath(int row, int col, char direction);

	// връща количеството боя разлята по пътя _path !!!
	int getPathAmauntOfPaint(string _path) const;

	// връща броя на завоите на пътя _path !!!
	int getPathTurns(string _path) const;

	// връща командите за пътя _path !!!
	string getPathCommands(string _path) const;

	Position* getPath(string _path);

};

#endif /* DRONE_H_ */
