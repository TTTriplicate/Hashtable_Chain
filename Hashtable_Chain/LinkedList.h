#pragma once

#include "Node.h"

class LinkedList {
private:
	Node* Head;
	void insert(Node* newNode);
	Node* findPreceding(int key);
	int ID = 0;
public:
	LinkedList();
	~LinkedList();
	void newNode(int key, int data);
	void newNode(int data);
	Node* search(int key);
	Node* findByData(int data);
	void remove(int key);
	void print();
	void tabbedPrint();
};