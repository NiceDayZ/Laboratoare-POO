#pragma once

#include "IPainter.h"
#include <string>
#include <map>

using namespace std;

class Canvas {
	int width;
	int heigth;
	char matrice[1000][1000];
	map<string, const IPainter *> paint;

public:
	Canvas(int w, int h);

	void AddPainter(string forma, const IPainter * tip);

	void Paint(string forma, int x, int y, int raza, char fill);

	void Paint(string forma, int x1, int y1, int x2, int y2, char fill);

	int GetWidth();

	int GetHeight();

	char& operator()(int x, int y);


};