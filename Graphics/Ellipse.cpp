#include<GL/glut.h>
#include <cmath>
#include <iostream>
#include "Ellipse.h"
#include "Line.h"
#include "Mouse.h"
using namespace std;

void Ellipse::Cirpot(int x0, int y0, int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f((x0 + x), (y0 + y));
	glVertex2f((x0 + x), (y0 - y));
	glVertex2f((x0 - x), (y0 - y));
	glVertex2f((x0 - x), (y0 + y));
	glEnd();
}

void Ellipse::MidPoint_Ellipse(int x0, int y0, int rx, int ry) {
	int x = 0;
	int y = ry;
	int px = 0;
	int py = 2 * rx*rx * y;
	Cirpot(x0, y0, x, y);
	int p = (ry*ry - (rx*rx * ry) + (0.25 * rx*rx));
	while (ry*ry*x < rx*rx*y) {
		x++;
		px += 2 * ry*ry;
		if (p < 0)
			p += ry*ry + px;
		else {
			y--;
			py -= 2 * rx*rx;
			p += ry*ry + px - py;
		}
		Cirpot(x0, y0, x, y);
	}
	p = (ry*ry * (x + 0.5) * (x + 0.5) + rx*rx *(y - 1) * (y - 1) - rx*rx * ry*ry);
	while (y > 0) {
		y--;
		py -= 2 * rx*rx;
		if (p > 0)
			p += rx*rx - py;
		else {
			x++;
			px += 2 * ry*ry;
			p += rx*rx - py + px;
		}
		Cirpot(x0, y0, x, y);
	}
}

void Ellipse::Draw() {
	set_color(lcolor);
	MidPoint_Ellipse(xlist[0], ylist[0], abs(xlist[0]-xlist[1]), abs(ylist[0]-ylist[1]));
	if (is_filled) {
		set_color(fcolor);
		Fill();
	}
}

bool Ellipse::is_selected(int x, int y) {
	int c = 0;
	int a, b;
	int distance = 0;
	if (abs(xlist[0] - xlist[1]) > abs(ylist[0] - ylist[1])) {
		a = abs(xlist[0] - xlist[1]);
		b = abs(ylist[0] - ylist[1]);
		c = sqrt(a*a - b*b);
		distance = sqrt(((ylist[0] - y)*(ylist[0] - y) + (xlist[0] - c - x)*(xlist[0] - c - x))) + sqrt((ylist[0] - y)*(ylist[0] - y) + (xlist[0] + c - x)*(xlist[0] + c - x));
		if (distance <= 2 * a)
			return true;
	}
	else {
		a = abs(ylist[0] - ylist[1]);
		b = abs(xlist[0] - xlist[1]);
		c = sqrt(a*a - b*b);
		distance = sqrt(((ylist[0] - c - y)*(ylist[0] - c - y) + (xlist[0] - x)*(xlist[0] - x))) + sqrt((ylist[0] + c - y)*(ylist[0] + c - y) + (xlist[0] - x)*(xlist[0] - x));
		if (distance <= 2 * a)
			return true;
	}
	return false;
}

void Ellipse::Fill() {
	int rx = abs(ylist[0] - ylist[1]), ry = abs(xlist[0] - xlist[1]);
	int x0 = xlist[0], y0 = ylist[0];
	glBegin(GL_POINTS);
	for (int i = x0 - ry; i < x0 + ry; i++) {
		for (int j = 0; j < 500; j++) {
			if (is_selected(i, j))
				glVertex2i(i, j);
		}
	}
	glEnd();
}

void Ellipse::Panning() {
	xlist[0] -= (begin_x - current_x);
	xlist[1] -= (begin_x - current_x);
	ylist[0] -= (begin_y - current_y);
	ylist[1] -= (begin_y - current_y);
	begin_x = current_x;
	begin_y = current_y;
}


static void Cirpot(int x0, int y0, int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f((x0 + x), (y0 + y));
	glVertex2f((x0 + x), (y0 - y));
	glVertex2f((x0 - x), (y0 - y));
	glVertex2f((x0 - x), (y0 + y));
	glEnd();
}


void MidPoint_Ellipse(int x0, int y0, int rx, int ry) {
	int x = 0;
	int y = ry;
	int px = 0;
	int py = 2 * rx*rx * y;
	Cirpot(x0, y0, x, y);
	int p = (ry*ry - (rx*rx * ry) + (0.25 * rx*rx));
	while (ry*ry*x < rx*rx*y) {
		x++;
		px += 2 * ry*ry;
		if (p < 0)
			p += ry*ry + px;
		else {
			y--;
			py -= 2 * rx*rx;
			p += ry*ry + px - py;
		}
		Cirpot(x0, y0, x, y);
	}
	p = (ry*ry * (x + 0.5) * (x + 0.5) + rx*rx *(y - 1) * (y - 1) - rx*rx * ry*ry);
	while (y > 0) {
		y--;
		py -= 2 * rx*rx;
		if (p > 0)
			p += rx*rx - py;
		else {
			x++;
			px += 2 * ry*ry;
			p += rx*rx - py + px;
		}
		Cirpot(x0, y0, x, y);
	}
}