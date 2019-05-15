// TestPO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Canvas.h"
#include "IPainter.h";
#include "Circle.h"
#include "Rectangle.h";
#include <iostream>
#include <map>

using namespace std;
/*
class IPainter { 
public:     
virtual void Paint(Canvas *c, int v1, int v2 = 0, int v3 = 0, int v4 = 0, int v5 = 0) = 0; 
};

class Circle : public IPainter {
public:
	void Paint(Canvas *c, int v1, int v2 = 0, int v3 = 0, int v4 = 0, int v5 = 0){

	}
};

class Rectangle : public IPainter {
	void Paint(Canvas *c, int v1, int v2 = 0, int v3 = 0, int v4 = 0, int v5 = 0) {

	}
};

class Canvas {
	int width;
	int heigth;
	char matrice[1000][1000];
	map<string, const IPainter*> paint;

public:
	Canvas(int w, int h) {
		width = w;
		heigth = h;
		for (int i = 0; i <= w; i++) {
			for (int j = 0; j <= h; j++) {
				matrice[i][j] = ' ';
			}
		}
	};

	void AddPainter(string forma,const IPainter * tip) {
		paint.insert(forma, tip);
	}

	void Paint(string forma, int x, int y, int raza, char fill) {
		for(int i = 0; i< width; i++)
			for(int j=0; j<heigth; j++)
				if ((i - x) * (i - x) + (j - y) * (j - y) <= raza * raza) 
					matrice[i][j] = fill;
				
	}

	void Paint(string forma, int x1, int y1, int x2, int y2, char fill) {
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				matrice[i][j] = fill;
			}
		}
	}

	int GetWidth() {
		return width;
	}

	int GetHeight() {
		return heigth;
	}

	char& operator()(int x, int y) {
		return matrice[x][y];
	}


};
*/

int main()
{
    
	//Canvas c; // ACEST COD NU VA COMPILA
	Canvas c(20, 20);
	c.AddPainter("cerc", new Circle());
	c.AddPainter("rect", new Rectangle());
	c(0, 0) = 'C'; c(1, 0) = '+'; c(2, 0) = '+';
	c.Paint("cerc", 5, 7, 3, 'x'); // cerc x=5,y=7, raza=3, fill='x'
	c.Paint("rect", 10, 10, 18, 14, 'd'); // dreptunghi (10,10) - (18,4) - fill='d'
	c.Paint("rect", 0, 19, 20, 19, '-');
	c.Paint("rect", 19, 0, 19, 19, '|');
	c(19, 19) = '+';
	for (int y = 0; y < c.GetHeight(); y++) {
		for (int x = 0; x < c.GetWidth(); x++)
			cout << c(x, y);
		cout << endl;
	}
	return 0;

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
