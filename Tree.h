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

	// основни операции

	// добавя numberPaths на брой пътища съдържащи се в paths към дърво
	void addPaths(const list<string> paths,int numberPaths);

	// добавя текущ път currentPath, започващ от връх currentNode
	void addPath(string& currentPath,node*& currentNode);

	// създава път в дърво от връх startNode и символи от path
	void createPath(string& path,node*& startNode);

	// намира общ път за path в дървото и добавя останалата част от path
	void foundSubPath(string& path,node*& node);

	// извежда четиритично дърво чрез gvedit.exe
	void print() const;

private:

	node* root; // указател към корена
	char* nodes; // указател към върховете на дървото
	int numberNodes; // брой на върховете на дървото
	int currentNode; // указва текущия връх

	string toFileString;

	// помощни член-функции

	// пълни стринга
	void fillToFileString(const node* p);

	// помощна функция за пълнене на стринга
	void fillToFileStringHelper(const node* p);

	// пълни масива с върхове
	void fillNodesArray(const node* _node);

};

#endif /* BINARYTREE_H_ */
