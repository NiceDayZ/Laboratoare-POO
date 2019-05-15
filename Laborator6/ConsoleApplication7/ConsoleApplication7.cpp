// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

ifstream f1("input.txt");



int convert(string s) {
	int numar = 0;
	for (int i = 0; i < s.length(); i++) {
		numar = numar * 10 + (s[i] - '0');
	}
	return numar;
}

set<int> sort() {
	string s;
	//string sfinal;
	set<int> sortedlist;
	getline(f1, s);
	int start = 0;
	while (s.find(",") != -1) {
		int poz = s.find(",");
		string nr = s.substr(start, poz - start);
		int number = convert(nr);
		sortedlist.insert(number);
		s = s.substr(poz + 1, s.length());
	}
	
	return sortedlist;
}




int main()
{
	string text;
	vector<string> cuvinte;
	map<string, int> M;

	getline(f1, text);

	string word = "";
	for (auto x : text)
	{
		if (x == ' ' || x=='?' || x=='!' || x==',' || x=='.')
		{
			cuvinte.push_back(word);
			M[word] = 0;
			word = "";
		}
		else
		{
			word = word + x;
			
		}
		
	}
	

	for (auto x : cuvinte) {
		M[x]++;
	}

	for (auto m : M) {
		if(m.first != "")
		cout << m.first << " " << m.second<< endl;
	}
	
	/*
	cout << "SORTED LIST:   ";
	set<int> sortedlist = sort();
	for (set<int>::iterator it = sortedlist.begin(); it != sortedlist.end(); ++it)
		std::cout << ' ' << *it;
	
    cout << endl << endl; 
	*/


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
