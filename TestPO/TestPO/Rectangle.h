#pragma once
#include "Canvas.h";
#include "IPainter.h";

class Rectangle : public IPainter {

	void Paint(Canvas *c, int v1, int v2 = 0, int v3 = 0, int v4 = 0, int v5 = 0);

};