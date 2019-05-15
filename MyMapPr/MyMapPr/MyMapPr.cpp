// MyMapPr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "pch.h"
#include "Header.h" 
#include <iostream>

int main()
{
	MyMap<int> mapi({ {"ceva",5},{"MM", 4},{"Suc de prune",16} });
	MyMap<int> mapi2({ {"ceva",6},{"MuM", 4},{"Suc de pruneee",16} });
	//cout << mapi["MM"];

	mapi.Add("altcevasdava", 123);
	mapi.Add("We <3 4t", 4);

	
	//MyMap<int> mapi3 = mapi & mapi2;

	mapi.Delete("MM");

	for (auto it : mapi|mapi2) {
		cout << it.first<<'\n';
	}

	//cout << (int)mapi3;
	

	
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
