#include <string>
#include <map>
#include "IPainter.h"

using namespace std;

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

	void AddPainter(string forma, const IPainter * tip) {
		paint.insert(forma, tip);
	}

	void Paint(string forma, int x, int y, int raza, char fill) {
		for (int i = 0; i < width; i++)
			for (int j = 0; j < heigth; j++)
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