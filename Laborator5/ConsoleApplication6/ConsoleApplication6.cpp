// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

#define ABC class
#define AAA public
#define INIT(x) x(0)
#define DACA(condition, trueS, falseS) if(condition) trueS; else falseS;
#define AFISEAZA(x) printf("%d ",(x))
#define CAT_TIMP(condition) while(condition){
#define ESTE_DIFERIT_DE !=
#define MAI_MARE_DECAT >
#define MINUS -
#define SFARSIT_CAT_TIMP }
#define X_DIN_T t.Get_x()
#define Y_DIN_T t.Get_y()
#define Z_DIN_T t.Get_z()
#define CREATE(x) void Set_##x(int value) {x = value;} int Get_##x() {return x;}

using namespace std;

ABC Test
{

 int x,y,z;

AAA:

 Test() : INIT(x), INIT(y), INIT(z) {}

 CREATE(x);

 CREATE(y);

 CREATE(z);


};

template <typename T>
class List
{
	T * Elemente;

	int Count, Allocated;

public:

	List() {
		Allocated = 100;
		Count = 0;
		Elemente = NULL;
	};
		
	~List() {
		Allocated = 0;
		Count = 0;
		Elemente = NULL;
	};

	bool Add(const T &value) {
		if (Count == 0) {
			Elemente = new T;
			Elemente[Count] = value;
			Count++;
			return true;
		}
		if (Count < Allocated) {
			T * p = new T;
			p = Elemente + Count;
			Elemente[Count] = value;
			Count++;
			return true;
		}
		else return false;
	}

	T& operator[] (int index) {
		return *(Elemente + index);
	};

	void Sort() {
		for (int i = 0; i < Count-1; i++) {
			for (int j = i+1; j < Count; j++) {
				if (Elemente[i] > Elemente[j]){
					T aux;
					aux = Elemente[j];
					Elemente[j] = Elemente[i];
					Elemente[i] = aux;
				}
			}
		}
	};

};

class Person {
	int Age;
	int Height;
	int Weight;

public:
	Person() {
		Age = 0;
		Height = 0;
		Weight = 0;
	}

	Person(int Age, int Weight,int Height) {
		this->Age = Age;
		this->Weight = Weight;
		this->Height = Height;
	}

	Person(Person &person) {
		Age = person.GetAge();
		Weight = person.GetHeight();
		Height = person.GetWeight();
	}

	bool operator> (Person person) {
		if (person.Age < Age) return true;
		else return false;
	}

	int GetAge() {
		return Age;
	}

	int GetHeight() {
		return Height;
	}

	int GetWeight() {
		return Weight;
	}

};

int main()

{
	
	Test t;

	t.Set_x(18);

	t.Set_y(24);

	AFISEAZA(t.Get_x() + t.Get_y());

	CAT_TIMP(X_DIN_T ESTE_DIFERIT_DE Y_DIN_T)

		DACA(X_DIN_T MAI_MARE_DECAT Y_DIN_T, t.Set_x(X_DIN_T MINUS Y_DIN_T), t.Set_y(Y_DIN_T MINUS X_DIN_T));

	SFARSIT_CAT_TIMP

		AFISEAZA(X_DIN_T);

		
		
	return 0;

}
//Codul compileaza si afiseaza pe ecran 42 6


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
