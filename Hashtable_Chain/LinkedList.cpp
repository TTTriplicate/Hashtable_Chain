/******************************
Class: LinkedList.cpp
Purpose: It's a linked list
******************************/

#include "LinkedList.h"
#include <iostream>
#include <exception>
#include <string>

//default constructor starts with just a nullptr
LinkedList::LinkedList() {
	Head = nullptr;
}

LinkedList::~LinkedList() {
	//iteratively deletes all Nodes in the list
	while (Head != nullptr) {
		Node* toDelete = Head;
		Head = Head->getNext();
		delete toDelete;
	}
};

void LinkedList::insert(Node* newNode) {
	//inserts nodes in ascending order, sorted by data value
	if (Head == nullptr) {
		Head = newNode;
	}
	else if (*(Head) > *(newNode)) {
		newNode->setNext(Head);
		Head = newNode;
	}
	else if (Head->getNext() == nullptr) {
		Head->setNext(newNode);
	}
	else {
		Node* next = Head;
		while (*(next->getNext()) < *(newNode)) {
			next = next->getNext();
			if (next->getNext() == nullptr) {
				next->setNext(newNode);
				return;
			}

		}
		newNode->setNext(next->getNext());
		next->setNext(newNode);
	}
}

void LinkedList::newNode(int key, int data) {
	//creates a new Node pointer and inserts it in the list
	Node* newNode = new Node(key, data);
	insert(newNode);
}

void LinkedList::newNode(int data) {
	//creates a new Node pointer and inserts it in the list
	Node* newNode = new Node(ID++, data);
	insert(newNode);
}

void LinkedList::print() {
	//iteratively writes the data of all Nodes in the list to the console
	if (Head != nullptr) {
		Node* toRead = Head;
		while (toRead != nullptr) {
			std::cout << "Item ID: " << toRead->getKey() << " Data: " << toRead->getData() << std::endl;
			toRead = toRead->getNext();
		}
	}
	else {
		throw std::invalid_argument("List is empty.");
	}
}

void LinkedList::tabbedPrint() {
	if (Head != nullptr) {
		Node* toRead = Head;
		while (toRead != nullptr) {
			std::cout << toRead->getData() << "\t";
			toRead = toRead->getNext();
		}
		std::cout << std::endl;
	}
	else {
		throw std::invalid_argument("List is empty.");
	}

}

Node* LinkedList::search(int key) {
	//linearly searches for a given node by Key value
	Node* currentNode = Head;
	while (currentNode != nullptr) {
		if (currentNode->getKey() == key) {
			return currentNode;
		}
		else {
			currentNode = currentNode->getNext();
		}
	}
	throw std::invalid_argument("No item found with key " + std::to_string(key));
}

Node* LinkedList::findByData(int data) {
	//linearly searches for a given node by Data value
	Node* currentNode = Head;
	while (currentNode != nullptr) {
		if (currentNode->getData() == data) {
			return currentNode;
		}
		else {
			currentNode = currentNode->getNext();
		}
	}
	throw std::invalid_argument("No item found with data " + std::to_string(data));
}

Node* LinkedList::findPreceding(int key) {
	//Searches for the node prior to the desired node for deletion
	Node* currentNode = Head;
	if (currentNode->getKey() == key) {
		throw std::runtime_error("Head match.  Readjust list.");
	}
	while (currentNode->getNext() != nullptr) {
		if (currentNode->getNext()->getKey() == key) {
			return currentNode;
		}
		else {
			currentNode = currentNode->getNext();
		}
	}
	throw std::invalid_argument("No item found with key " + std::to_string(key));
}

void LinkedList::remove(int key) {
	//finds and deletes a node by key value
	Node* toDelete;
	try {
		toDelete = this->findPreceding(key);
	}
	catch (std::runtime_error e) {//found at head
		toDelete = Head;
		Head = Head->getNext();
		delete toDelete;
	}
	toDelete->setNext(toDelete->getNext());
}