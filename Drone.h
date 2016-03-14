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

	// �������� ������� �� ���-������ ������ �� ��� �� ����� !!!
	void printPathsTree() const;

	// �������� ������ ������ � ���-���� �������
	// �� ��� �� ����� !!!
	void printAllShortestPaths();

	// ������� ������ ���-������ ������� �� ��� �� �����
	void printALLShortestCommands();

	// ������� ���� �� ������� �� ����� �� �������� !!!
	void printPathsTurns() const;

	// ������� ������������ ��� ������� �� ����� �� �������� !!!
	void printAmauntOfPaint() const;

	// ����� ��������� �� ���-����� ��� !!!
	int getShortestLength() const;

	// ��������� ������� ����� �� ����� leaf
	// ���� ������� ������� ��������� ����� ��� ������ �� ������ � ����� ��,
	// ��������� �� ����,������������ ������� ��� � ���� ����� �� ���� ���
	void chooseLeaf(unsigned int leaf) const;

	// ����� 1
	// ������ ���� �� ����� ���� �� �� ������ ���-����� ��� �
	// � ��� ���� �� ��� �������� ��� ����� ���� �����
	void maxPaintPath();

	// ����� 2
	// ������ � ��� �����, �������� �� ���-������ ����� ��
	// ��������� �� ����� � ���������� �� ���������, �����
	// ������ �� �� ������� � ����� �����
	void twoDronesWorks();

	bool areInSamePosition(Position* firstPath, Position* secondPath,int length) const;

private:

	Tree shortestPathsTree; // ������� �� ���������

	CreateRoom myRoom; // ���� ���������� �� ������

	list<string> allPaths; // ������ ������
	list<string> shortestPaths; // ������ ���-������ ������

	string path; // ����� ���
	int position; // ����� ������� �� ������ �� ����� �� ��������� �� ����

	unsigned int shortestLength; // ���� ���-������ ������� �� ���� !!!

	// ������ ������ ���-���� ������ �� ��� �� �����,
	// ������� �� � ������� shortestPaths
	void findShortestPaths();

	// ������ ������ ������ �� ��� �� �����
	// row � ��������� x-������������ �� ���
	// col � ��������� y-������������ �� ���
	// ����� ���� � ���������� �����
	// direction � �������� ������ �� �����
	void findPath(int row, int col, char direction);

	// ����� ������������ ��� ������� �� ���� _path !!!
	int getPathAmauntOfPaint(string _path) const;

	// ����� ���� �� ������� �� ���� _path !!!
	int getPathTurns(string _path) const;

	// ����� ��������� �� ���� _path !!!
	string getPathCommands(string _path) const;

	Position* getPath(string _path);

};

#endif /* DRONE_H_ */
