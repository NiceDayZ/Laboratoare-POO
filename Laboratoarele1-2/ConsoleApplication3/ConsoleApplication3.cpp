// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//LABORATOR POO
//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C4996	'fopen': This function or variable may be unsafe.Consider using fopen_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.ConsoleApplication3	c : \users\craci\source\repos\consoleapplication3\consoleapplication3\consoleapplication3.cpp	12
/*

#include "pch.h"
#include <iostream>
#include <stdio.h>

int main()
{
	FILE* f = fopen("Text.txt", "r");
    
	char linie[1000]; int i = 0;
	int a[1000];
	while (fgets(linie, 1000, f)  != NULL) {
		a[i] = atoi(linie);
		i++;
	}

	

	for (int j = 0; j < i - 1; j++) {
		for (int k = j; k < i; k++) {
			if (a[j] > a[k]) {
				int aux = a[j];
				a[j] = a[k];
				a[k] = aux;
			}
		}


	}
	for (int j = 0; j < i; j++) {
		std::cout << a[j] << ' ';
	}

	fclose(f);
}

*/
#define _CRT_SECURE_NO_WARNINGS
#define MATRIX_HEIGHT 8
#define MATRIX_WIDTH 7
#include <iostream>
#include <stdio.h>

using namespace std;

int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];



/*
void afisareMatrice(int* ptr) {
	for (int i = 0; i < MATRIX_HEIGHT; i++) {
		for (int j = 0; j < MATRIX_WIDTH; j++)
			std::cout << *(ptr + i * MATRIX_WIDTH + j)<<' ';
		std::cout << '\n';
	}
}

	void Circle(int* ptr, int cx, int cy, int ray) {
		for (int i = 0; i < MATRIX_HEIGHT; i++) {
			for (int j = 0; j < MATRIX_WIDTH; j++)
				if ((i - cx)*(i - cx) + (j - cy)*(j - cy) == ray*ray)
					*(ptr + i * MATRIX_WIDTH + j) = 1;
		}

	
	}

bool Convert(unsigned int number, unsigned int toBase, char * result, unsigned int resultMaxSize) {
	if (toBase > 16)
		return false;
	int rest;
	int contor = 0;
	char c[20];
	while (number > 0) {
		rest = number % toBase;
		number /= toBase;
		if(rest<10)
			c[contor] = rest + '0';
		else if (rest == 15) {
			c[contor] = 'f';
		}
		else if(rest == 14) {
			c[contor] = 'e';
		}
		else if (rest == 13) {
			c[contor] = 'd';
		}
		else if (rest == 12) {
			c[contor] = 'c';
		}
		else if (rest == 11) {
			c[contor] = 'b';
		}
		else if (rest == 10) {
			c[contor] = 'a';
		}
		contor++;
		//strcat(result, char rest+'0');
	}
	for (int i = 0; i <= contor; i++) {
		std::cout << c[contor];
	}
}
*/

class MyString
{
public:
	char * sir;
	unsigned int AllocatedSize;
	unsigned int Size;

	MyString() {
		sir = new char[16];
		for (int i = 0; i < 16; i++) sir[i] = '\0';

		Size = 0;
		AllocatedSize = 16;
	}

	MyString(const char* text) {
		sir = new char[16];
		Size = AllocatedSize = 0;
		Set(text);
	}

	void Set(const char* text) {
		int lungime = strlen(text);
		
		if (lungime < AllocatedSize) {
			strcpy(sir, text);
			Size = strlen(text);
			return;
		}
		delete[] sir;
		sir = new char[lungime + 1];
		strcpy(sir, text);
		AllocatedSize = lungime + 1;
		Size = lungime;
	}

	void Set(MyString& s) {
		Set(s.sir);
	}

	void Add(const char *text) {
		int lungime = strlen(text) + Size;
		
		
		if (lungime < AllocatedSize) {
			strcat(sir, text);
			Size = lungime;
			return;
		}
		
		char* temp = new char[Size];
		for (int i = 0; i < Size; i++) temp[i] = sir[i];

		delete[] sir;
		sir = new char[lungime + 1];

		for (int i = 0; i <= lungime; i++) sir[i] = '\0';
		for (int i = 0; i < Size; i++) sir[i] = temp[i];
		
		strcat(sir, text);
		AllocatedSize = lungime + 1;
		Size = lungime;
	}

	void Add(MyString& s) {
		Add(s.sir);
	}

	bool Insert(unsigned int index, const char* text)
	{
		if (index >= strlen(sir))
			return false;

		char copie[1000];
		strcpy(copie, sir);
		if (strlen(sir) + strlen(text) > AllocatedSize)
		{
			delete[] sir;
			sir = new char[strlen(copie) + strlen(text) + 1];
			strcpy(sir, copie);
			strcpy(sir + index, text);
			strcat(sir, copie + index);
			Size = strlen(copie) + strlen(text);
			AllocatedSize = strlen(copie) + strlen(text) + 1;
		}
		strcpy(sir + index, text);
		strcat(sir, copie + index);
		Size = strlen(copie) + strlen(text);
		return true;
	}
	bool Insert(unsigned int index, MyString &m)
	{
		if (index >= strlen(sir))
			return false;
		return Insert(index, m.sir);
	}


	~MyString() {
		cout << "S-a apelat destructorul";
	}

	const char* GetText() {
		return sir;
	}
};

void main() {
	MyString s;
	s.Set("test");

	MyString s2("ceva");

	s2.Add("Altceva");
	s.Insert(2,"1234567890");

	cout<<s.GetText()<<'\n';
	cout << s2.GetText() << '\n';
	//MyString s3("Test");

	
	//cout << s3.GetText() <<'\n';

	
}