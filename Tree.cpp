/*
 * Tree.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: zyapkov
 */

#include <iostream>
#include <cassert>
#include "Tree.h"
#include <sstream>
#include <fstream>
#include <windows.h>
using namespace std;

Tree::Tree() {

	root = NULL;
	nodes = NULL;
	numberNodes = 0;
	currentNode = 0;
	toFileString = "graph {\n";
}

Tree::~Tree() {

	delete[] nodes;
	delete[] root;

}

void Tree::addPaths(const list<string> paths, int numberPaths) {

	string* temp = new string[numberPaths];

	int j = -1;
	for (list<string>::const_iterator it = paths.begin(); it != paths.end();
			it++) {
		j++;
		temp[j] = 'S' + *it;
	}

	int i = 0;

	root = new node;
	root->info = 'S';
	root->number = 1;
	root->first = NULL;
	root->second = NULL;
	root->third = NULL;
	root->fourth = NULL;

	numberNodes++;
	currentNode++;

	while (i < numberPaths) {
		addPath(temp[i], root);
		i++;
	}

	nodes = new char[numberNodes];

	currentNode = -1;

	fillNodesArray(root);
	fillToFileString(root);
}

void Tree::addPath(string& currentPath, node*& _currentNode) {

	if (_currentNode == NULL) {

		createPath(currentPath, _currentNode);

	} else {

		node* temp = root;

		foundSubPath(currentPath, temp);

		if (temp->first == NULL) {
			if (currentPath.size() > 0) {
				createPath(currentPath, temp->first);
			}
		} else {
			if (temp->second == NULL) {
				if (currentPath.size() > 0)
					createPath(currentPath, temp->second);
			} else {

				if (temp->third == NULL) {
					if (currentPath.size() > 0) {
						createPath(currentPath, temp->third);
					}
				} else {

					if (currentPath.size() > 0) {
						createPath(currentPath, temp->fourth);
					}

				}

			}
		}

	}

}

void Tree::foundSubPath(string& path, node*& node) {

	if (node) {

		if (path.at(0) != node->info) {
			return;
		} else {

			path = path.substr(1);

			if (node->first) {
				if (node->first->info == path.at(0)) {
					node = node->first;
					foundSubPath(path, node);
					return;
				}
			}
			if (node->second) {
				if (node->second->info == path.at(0)) {
					node = node->second;
					foundSubPath(path, node);
					return;
				}
			}

			if (node->third) {
				if (node->third->info == path.at(0)) {
					node = node->third;
					foundSubPath(path, node);
					return;
				}
			}

			if (node->fourth) {
				if (node->fourth->info == path.at(0)) {
					node = node->fourth;
					foundSubPath(path, node);
					return;
				}
			}

		}

	}

}

void Tree::createPath(string& path, node*& position) {

	if (path.size() > 0) {
		currentNode++;

		position = new node;
		assert(position != NULL);
		numberNodes++;

		position->number = currentNode;
		position->info = path.at(0);
		position->first = NULL;
		position->second = NULL;
		position->third = NULL;
		position->fourth = NULL;

		path = path.substr(1);

		createPath(path, position->first);

	} else {
		return;
	}

}

void Tree::print() const {

	ofstream fileWriter("Print.txt");

	if (fileWriter.is_open()) {
		fileWriter << toFileString;

		fileWriter.close();
	}

	ShellExecute(NULL, "Open",
			"D:\\DOWNLOAD\\graphviz-2.38\\release\\bin\\gvedit.exe",
			"D:\\DOWNLOAD\\Eclipse\\workspace\\TomAndJerry\\TomAndJerry\\Print.txt",
			NULL, SW_SHOWNORMAL);

}

void Tree::fillNodesArray(const node* _node) {

	if (_node) {

		currentNode++;
		nodes[currentNode] = _node->info;

		if (_node->first) {
			fillNodesArray(_node->first);
		}

		if (_node->second) {
			fillNodesArray(_node->second);
		}

		if (_node->third) {
			fillNodesArray(_node->third);
		}

		if (_node->fourth) {
			fillNodesArray(_node->fourth);
		}
	}
}

void Tree::fillToFileString(const node* p) {

	toFileString = toFileString + "1[ label = \"START\"];\n";

	int current = 1;

	for (int i = 1; i < numberNodes; i++) {

		current++;
		ostringstream temp;
		temp << current << "[ label = \"" << nodes[i] << "\"];\n";
		toFileString = toFileString + temp.str();
	}

	fillToFileStringHelper(p);

	toFileString = toFileString + "}\n";
}

void Tree::fillToFileStringHelper(const node* p) {

	if (p) {

		if (p->first) {

			ostringstream temp;
			temp << p->number << "--" << p->first->number << ";\n";
			toFileString = toFileString + temp.str();
			fillToFileStringHelper(p->first);
		}
		if (p->second) {
			ostringstream temp;
			temp << p->number << "--" << p->second->number << ";\n";
			toFileString = toFileString + temp.str();
			fillToFileStringHelper(p->second);
		}

		if (p->third) {
			ostringstream temp;
			temp << p->number << "--" << p->third->number << ";\n";
			toFileString = toFileString + temp.str();
			fillToFileStringHelper(p->third);
		}

		if (p->fourth) {
			ostringstream temp;
			temp << p->number << "--" << p->fourth->number << ";\n";
			toFileString = toFileString + temp.str();
			fillToFileStringHelper(p->fourth);
		}
	}

}
