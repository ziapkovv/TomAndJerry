/*
  * BinaryTree.h
 *
 *  Created on: Dec 29, 2015
 *      Author: zyapkov
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
#include <string>
#include<list>
using namespace std;

struct node {

	int number;
	char info;
	node* first;
	node* second;
	node* third;
	node* fourth;

	void print() {
		cout << "info:" << info << endl;
	}

};

class Tree {

public:

	Tree();
	~Tree();

	// ������� ��������

	// ������ numberPaths �� ���� ������ ��������� �� � paths ��� �����
	void addPaths(const list<string> paths,int numberPaths);

	// ������ ����� ��� currentPath, �������� �� ���� currentNode
	void addPath(string& currentPath,node*& currentNode);

	// ������� ��� � ����� �� ���� startNode � ������� �� path
	void createPath(string& path,node*& startNode);

	// ������ ��� ��� �� path � ������� � ������ ���������� ���� �� path
	void foundSubPath(string& path,node*& node);

	// ������� ����������� ����� ���� gvedit.exe
	void print() const;

private:

	node* root; // �������� ��� ������
	char* nodes; // �������� ��� ��������� �� �������
	int numberNodes; // ���� �� ��������� �� �������
	int currentNode; // ������ ������� ����

	string toFileString;

	// ������� ����-�������

	// ����� �������
	void fillToFileString(const node* p);

	// ������� ������� �� ������� �� �������
	void fillToFileStringHelper(const node* p);

	// ����� ������ � �������
	void fillNodesArray(const node* _node);

};

#endif /* BINARYTREE_H_ */
