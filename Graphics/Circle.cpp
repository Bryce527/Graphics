#include<GL/glut.h>
#include <cmath>
#include <iostream>
#include "BasicDrawing.h"
#include "Circle.h"
#include "Line.h"
#include "Mouse.h"
using namespace std;

void Circle::Cirpot(int x0, int y0, int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f((x0 + x), (y0 + y));
	glVertex2f((x0 + y), (y0 + x));
	glVertex2f((x0 + y), (y0 - x));
	glVertex2f((x0 + x), (y0 - y));
	glVertex2f((x0 - x), (y0 - y));
	glVertex2f((x0 - y), (y0 - x));
	glVertex2f((x0 - y), (y0 + x));
	glVertex2f((x0 - x), (y0 + y));
	glEnd();
}

void Circle::MidPoint_Circle(int x0, int y0, int r) {
	int x = 0;
	int y = r;
	int d = (int) (5/4 - r);
	Cirpot(x0, y0, x, y);
	while (x < y) {
		if (d < 0) {
			d += (2 * x + 3);
		}
		else {
			d += (2 * (x + 1) + 3 - 2 * y -2);
			y--;
		}
		x++;
		Cirpot(x0, y0, x, y);
	}
}

void Circle::Draw() {
	set_color(lcolor);
	int r = sqrt((xlist[0] - xlist[1])*(xlist[0] - xlist[1]) + (ylist[0] - ylist[1])*(ylist[0] - ylist[1]));
	MidPoint_Circle(xlist[0], ylist[0], r);
	if (is_filled) {
		set_color(fcolor);
		Fill();
	}
}

bool Circle::is_selected(int x, int y) {
	int r = sqrt((xlist[0] - xlist[1])*(xlist[0] - xlist[1]) + (ylist[0] - ylist[1])*(ylist[0] - ylist[1]));
	int distance = sqrt((xlist[0] - x)*(xlist[0] - x) + (ylist[0] - y)*(ylist[0] - y));
	if (distance <= r)
		return true;
	else return false;
}


void Circle::Fill() {
	int x0 = xlist[0], y0 = ylist[0];
	int r = sqrt((xlist[0] - xlist[1])*(xlist[0] - xlist[1]) + (ylist[0] - ylist[1])*(ylist[0] - ylist[1]));
	glBegin(GL_POINTS);
	for (int i = x0 - r; i < x0 + r; i++) {
		for (int j = 0; j < 500; j++) {
			if (is_selected(i, j))
				glVertex2i(i, j);
		}
	}
	glEnd();
}


static void Cirpot(int x0, int y0, int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f((x0 + x), (y0 + y));
	glVertex2f((x0 + y), (y0 + x));
	glVertex2f((x0 + y), (y0 - x));
	glVertex2f((x0 + x), (y0 - y));
	glVertex2f((x0 - x), (y0 - y));
	glVertex2f((x0 - y), (y0 - x));
	glVertex2f((x0 - y), (y0 + x));
	glVertex2f((x0 - x), (y0 + y));
	glEnd();
}
void MidPoint_Circle(int x0, int y0, int r) {
	int x = 0;
	int y = r;
	int d = (int)(5 / 4 - r);
	Cirpot(x0, y0, x, y);
	while (x < y) {
		if (d < 0) {
			d += (2 * x + 3);
		}
		else {
			d += (2 * (x + 1) + 3 - 2 * y - 2);
			y--;
		}
		x++;
		Cirpot(x0, y0, x, y);
	}
}


void Circle::Panning() {
	xlist[0] -= (begin_x - current_x);
	xlist[1] -= (begin_x - current_x);
	ylist[0] -= (begin_y - current_y);
	ylist[1] -= (begin_y - current_y);
	begin_x = current_x;
	begin_y = current_y;
}