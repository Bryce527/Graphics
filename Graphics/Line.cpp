#include<GL/glut.h>
#include <cmath>
#include <iostream>
#include "BasicDrawing.h"
#include "Line.h"
#include "Mouse.h"
using namespace std;

void Line::LineBresenham(int xBegin, int yBegin, int xEnd, int yEnd) {
	int dx = fabs((double)(xEnd - xBegin));
	int dy = fabs((double)(yEnd - yBegin));
	int p = 2 * dy - dx;
	int two_dy = 2 * dy;
	int two_dx = 2 * dx;
	int two_dy_minus_dx = 2 * (dy - dx);
	int two_dx_minus_dy = 2 * (dx - dy);
	int x, y;
	int xName, yName;
	if (xBegin == xEnd && yBegin == yEnd)
		return;
	if (dy <= dx) {		//斜率小于1
		if (xBegin > xEnd) {
			yName = yBegin - yEnd;
			x = xEnd;
			y = yEnd;
			xEnd = xBegin;
		}
		else {
			yName = yEnd - yBegin;
			x = xBegin;
			y = yBegin;
		}
		while (x <= xEnd) {
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
			if (dx == 0 && y < yEnd) {
				y++;
			}
			else {
				if (p < 0) {
					x++;
					p += two_dy;
				}
				else if (yName > 0) {
					y++;
					x++;
					p += two_dy_minus_dx;
				}
				else if (yName < 0) {
					y--;
					x++;
					p += two_dy_minus_dx;
				}
			}

		}
	}
	else {		//斜率大于1
		if (yBegin > yEnd) {
			xName = xBegin - xEnd;
			x = xEnd;
			y = yEnd;
			yEnd = yBegin;
		}
		else {
			xName = xEnd - xBegin;
			x = xBegin;
			y = yBegin;
		}
		while (y <= yEnd) {
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
			if (dx == 0 && y <= yEnd) {
				y++;
			}
			else {
				if (p < 0) {
					y++;
					p += two_dx;
				}
				else if (xName > 0) {
					y++;
					x++;
					p += two_dx_minus_dy;
				}
				else if (xName < 0) {
					x--;
					y++;
					p += two_dx_minus_dy;
				}
			}
		}
	}

}

void Line::Draw() {
	set_color(lcolor);
	LineBresenham(xlist[0], ylist[0], xlist[1], ylist[1]);
}

void Line::Fill() {
}

bool Line::is_selected(int x, int y) {
	double distance = 0.0;
	if (xlist[0] == xlist[1]) {
		distance = abs(x - xlist[0]);
		if (distance <= 10.0)
			return true;
	}
	else {
		double k = (double)(ylist[1] - ylist[0]) / (double)(xlist[1] - xlist[0]);
		double b = (double)ylist[0] - k * xlist[0];
		distance = (fabs(k*x - y + b)) / sqrt(k*k+1);
		cout << "k distance " << k << " " << distance << endl;
		if (distance <= 10.0)
			return true;
	}
	return false;
}


void LineBresenham(int xBegin, int yBegin, int xEnd, int yEnd) {
	int dx = fabs((double)(xEnd - xBegin));
	int dy = fabs((double)(yEnd - yBegin));
	int p = 2 * dy - dx;
	int two_dy = 2 * dy;
	int two_dx = 2 * dx;
	int two_dy_minus_dx = 2 * (dy - dx);
	int two_dx_minus_dy = 2 * (dx - dy);
	int x, y;
	int xName, yName;
	if (xBegin == xEnd && yBegin == yEnd)
		return;
	if (dy <= dx) {		//斜率小于1
		if (xBegin > xEnd) {
			yName = yBegin - yEnd;
			x = xEnd;
			y = yEnd;
			xEnd = xBegin;
		}
		else {
			yName = yEnd - yBegin;
			x = xBegin;
			y = yBegin;
		}
		while (x <= xEnd) {
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
			if (dx == 0 && y < yEnd) {
				y++;
			}
			else {
				if (p < 0) {
					x++;
					p += two_dy;
				}
				else if (yName > 0) {
					y++;
					x++;
					p += two_dy_minus_dx;
				}
				else if (yName < 0) {
					y--;
					x++;
					p += two_dy_minus_dx;
				}
			}

		}
	}
	else {		//斜率大于1
		if (yBegin > yEnd) {
			xName = xBegin - xEnd;
			x = xEnd;
			y = yEnd;
			yEnd = yBegin;
		}
		else {
			xName = xEnd - xBegin;
			x = xBegin;
			y = yBegin;
		}
		while (y <= yEnd) {
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
			if (dx == 0 && y <= yEnd) {
				y++;
			}
			else {
				if (p < 0) {
					y++;
					p += two_dx;
				}
				else if (xName > 0) {
					y++;
					x++;
					p += two_dx_minus_dy;
				}
				else if (xName < 0) {
					x--;
					y++;
					p += two_dx_minus_dy;
				}
			}
		}
	}

}


void Line::Panning() {
	xlist[0] -= (begin_x - current_x);
	xlist[1] -= (begin_x - current_x);
	ylist[0] -= (begin_y - current_y);
	ylist[1] -= (begin_y - current_y);
	begin_x = current_x;
	begin_y = current_y;
}