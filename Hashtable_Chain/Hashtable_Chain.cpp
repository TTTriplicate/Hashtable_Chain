/*************************************
Program: Hashtable_Chain.cpp
Purpose: Hashtable for analysis
Author: Chris Sousa
Date: 09/21/2020
*****************************************/


#include <iostream>
#include <ctime>
#include "LinkedList.h"

int generateRandomNumber();

void searchTable(LinkedList* hashtable);

int main()
{
	srand(std::time(NULL));
	LinkedList hashtable[10];

	for (int i = 0; i < 25; i++) {
		int newNumber = generateRandomNumber();
		hashtable[newNumber % 10].newNode(newNumber);
	}

	for (int i = 0; i < 10; i++) {
		std::cout << "Contents of list " << i << ":" << std::endl;
		try {
			hashtable[i].tabbedPrint();
		}
		catch (std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	searchTable(hashtable);

	return 0;
}

int generateRandomNumber() {
	return rand() % 100;
}

void searchTable(LinkedList* hashtable) {
	int input = 0;
	while (input != -1) {
		std::cout << "Enter a number between 1 and 100 to search for, or -1 to exit:" << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (input == -1) {
			break;
		}
		try {
			Node* found = hashtable[input % 10].findByData(input);
			std::cout << "Found requested number in list " << input % 10 << " Node " << found->getKey() << std::endl;
		}
		catch (std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

}