#include "pch.h"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       



class Container {
public:
	virtual bool Add(int value) = 0;
	virtual bool Del(int value) = 0;
	virtual int  Count(int value) = 0;
	virtual bool Exists(int value) = 0;
	virtual int* GetSortedArray() = 0;
	virtual int  GetCount() = 0;
};

class Node {
public:
	int value;
	Node* next;
	Node(int val) {
		value = val;
	}
};

class Tree {
public:
	int value;
	Tree* left;
	Tree* right;
	Tree(int val) {
		value = val;
	}
};

class LinkedList : public Container {
private:
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}

	bool Add(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			tmp->next = newNode;
		}
		return true;
	}

	bool Del(int value) {
		if (head == nullptr)
			return false;
		Node* tmp = head;
		while (tmp->next != nullptr) {
			if (tmp->next->value == value) {
				Node* toDelete = tmp->next;
				tmp->next = tmp->next->next;
				toDelete->next = nullptr;
				delete toDelete;
				return true;
			}
			tmp = tmp->next;
		}
		return false;
	}

	int Count(int value) {
		int counter = 0;
		Node* tmp = head;
		while (tmp != nullptr) {
			counter += (tmp->value == value);
			tmp = tmp->next;
		}
		return counter;
	}


	bool Exists(int value) {
		Node* tmp = head;
		while (tmp != nullptr) {
			if (tmp->value == value)
				return true;
			tmp = tmp->next;
		}
		return false;
	}

	int GetCount() {
		int counter = 0;
		Node* tmp = head;
		while (tmp != nullptr) {
			counter++;
			tmp = tmp->next;
		}
		return counter;
	}

	int* GetSortedArray() {
		int* arr = new int[GetCount()];
		int idx = 0;
		Node* tmp = head;
		while (tmp != nullptr) {
			arr[idx++] = tmp->value;
			tmp = tmp->next;
		}

		for (int i = 0; i < idx; ++i)
			for (int j = i + 1; j < idx; ++j)
				if (arr[i] > arr[j]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}

		return arr;
	}

	void PrintList() {
		Node* tmp = head;
		while (tmp != nullptr) {
			std::cout << tmp->value << ' ';
			tmp = tmp->next;
		}
		//std::cout << std::endl;
	}
};



int main() {
	LinkedList list = LinkedList();
	srand(time(0));
	std::cout << time(0) << std::endl;

	for (int i = 1; i <= 10; ++i)
		list.Add( rand()%10+1 );

	list.PrintList();

	std::cout <<" << Generated list "<< std::endl << std::endl;

	int* arr = new int[list.GetCount()];
	arr = list.GetSortedArray();

	for (int i = 0; i < list.GetCount(); i++) 
		std::cout << arr[i] << ' ';

	std::cout << " << Sorted list" << std::endl << std::endl;

	list.Add(11);

	list.PrintList();

	std::cout << " << Add a value(11)" << std::endl << std::endl;

	list.Del(11);

	list.PrintList();

	std::cout << " << Delete a value(11)" << std::endl << std::endl;

	std::cout << list.GetCount() << " << Get Count" << std::endl << std::endl;

	std::cout << list.Count(5) << " << Count(5)" << std::endl << std::endl;

	std::cout << list.Exists(5) << " << Exist(5)" << std::endl << std::endl;


	return 0;
}