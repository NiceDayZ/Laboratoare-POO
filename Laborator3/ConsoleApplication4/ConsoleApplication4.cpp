// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

class BigNumber {

private:

	char Number[256];

	int  CharactersCount;

public:

	BigNumber() {
		Number[0] = 0;
		
		for (int i = 0; i < 256; i++) {
			Number[i] = 0;
		}

		
		//cout << sizeof Number;
		CharactersCount = 1;

		
	} // Constructor implicit (creaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]

	BigNumber(int value) {
		memset(Number, 0, sizeof Number);
		Set(value);
	}

	



	bool Set(int value) {
		if (value < 0) return false;

		CharactersCount = 0;

		if (value == 0) {
			CharactersCount = 1;
		}

		while (value > 0) {
			Number[CharactersCount] = value % 10;
			value /= 10;
			CharactersCount++;
		}
		//printNumber();
		return true;
	}


	void printNumber() {
		for (int i = CharactersCount-1; i >= 0; i--) {
			cout <<(char) (Number[i] + '0');
		}
		cout << endl;
	}


	BigNumber operator+ (const BigNumber & number) {
		BigNumber result(0);

		int rest = 0;
		char temp;
		result.CharactersCount = max(CharactersCount, number.CharactersCount);

		for (int i = 0; i < max(CharactersCount,number.CharactersCount); i++) {
			
			

			temp = (Number[i] + number.Number[i]);
			

			result.Number[i] = temp % 10;

			if (rest) result.Number[i]++;

			if (result.Number[i] > 9) {
				result.Number[i] %= 10;
				rest = 1;
			}else {
				if (temp >= 10) rest = 1;
				else rest = 0;
			}
			
		}
		if (rest) {
			result.Number[CharactersCount] = 1;
			result.CharactersCount++;
		}
		return result;
	}

	BigNumber operator* (const BigNumber & number) {
		BigNumber result(0);
		int power10 = 1;
		for (int i = 0; i < number.CharactersCount; i++) {
			

			for (int j = 1; j <= (number.Number[i] * power10); j++)
				result = result + *this;

			power10 = power10 * 10;
		}
		return result;
	}
	
};

int main()
{
	BigNumber number;
	number.Set(25);

	BigNumber number2;
	number2.Set(2);

	BigNumber number3 = number + number2;

	number3.printNumber();
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
