// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Multime.h"
#include <iostream>


int compareUP(int x, int y) {
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}


int main()
{
	int a[3] = { 3,2,1 };
	int b[2] = { 1,10 };

	Multime m1(a, 3);
	Multime m2(b, 2);

	std::cout << "Multimea 1:    ";
	for (int i = 0; i < m1.GetSize(); i++) {
		std::cout << m1[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "Multimea 2:    ";
	for (int i = 0; i < m2.GetSize(); i++) {
		std::cout << m2[i] << ' ';
	}
	std::cout << '\n';

	m1.Sort(compareUP);

	std::cout << "Multimea 1 sortata:    ";
	for (int i = 0; i < m1.GetSize(); i++) {
		std::cout << m1[i] << ' ';
	}
	std::cout << '\n';

	Multime m3 = m1 & m2;
	Multime m4 = m1 | m2;

	std::cout << "Multimea 1 & Multimea 2:    ";
	for (int i = 0; i < m3.GetSize(); i++) {
		std::cout << m3[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "Multimea 1 | Multimea 2:     ";
	for (int i = 0; i < m4.GetSize(); i++) {
		std::cout << m4[i] << ' ';
	}
	std::cout << '\n';


    //std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
