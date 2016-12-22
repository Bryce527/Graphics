#include<GL/glut.h>
#include<iostream>
#include <cmath>
#include "BasicDrawing.h"
#include "FillArea.h"
#include "Common.h"
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Graphics.h"
#include "Display.h"

int begin_x, begin_y;
int current_x, current_y;
int list_index = 0;
int Xlist[100], Ylist[100];
int FLAG = 0;
int COLORFLAG = 0;
int SELECTED = 0;

void mymouse(int button, int state, int x, int y) {
	if (FLAG == LINE) {
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
			begin_x = x;
			begin_y = 500-y;
		}
		else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
			Line *bd = new Line;
			bd->set_type(LINE);
			bd->add_point(begin_x, begin_y);
			bd->add_point(current_x, current_y);
			bd->set_lcolor(COLORFLAG);
			graphics.Add_to_list(bd);
			printf("add success");
		}
		else if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
			printf("right\n");
		}
	}
	else if (FLAG == CIRCLE) {
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
			begin_x = x;
			begin_y = 500-y;
		}
		else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
			Circle* bd = new Circle;
			bd->set_type(CIRCLE);
			bd->add_point(begin_x, begin_y);
			bd->add_point(current_x, current_y);
			bd->set_lcolor(COLORFLAG);
			graphics.Add_to_list(bd);
		}
		else if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
			printf("right\n");
		}
	}
	else if (FLAG == ELLIPSE) {
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
			begin_x = x;
			begin_y = 500-y;
		}
		else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
			Ellipse* bd = new Ellipse;
			bd->set_type(ELLIPSE);
			bd->add_point(begin_x, begin_y);
			bd->add_point(current_x, current_y);
			bd->set_lcolor(COLORFLAG);
			graphics.Add_to_list(bd);
		}
		else if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
			printf("right\n");
		}
	}
	else if (FLAG == POLYGON) {
		printf("多边形\n");
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
			Xlist[list_index] = x;
			Ylist[list_index] = 500-y;
			if (list_index != 0) {
				LineBresenham(Xlist[list_index - 1], Ylist[list_index - 1], Xlist[list_index], Ylist[list_index]);
				glFlush();
			}
			list_index++;
		}
		else if ((button == GLUT_MIDDLE_BUTTON) && (state == GLUT_DOWN)) {
			LineBresenham(Xlist[list_index - 1], Ylist[list_index - 1], Xlist[0], Ylist[0]);
			glFlush();
			Polygon* bd = new Polygon;
			bd->set_type(POLYGON);
			for (int i = 0; i < list_index; i++) {
				bd->add_point(Xlist[i], Ylist[i]);
			}
			bd->set_lcolor(COLORFLAG);
			graphics.Add_to_list(bd);
			list_index = 0;
			printf("right\n");
		}
	}
	else if (FLAG == FILLAREA) {
		printf("in fillarea\n");
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
			begin_x = x;
			begin_y = 500-y;
			display();
			while ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
				cout << "in\n";
			}
//			display();
		}
	}
	else if (FLAG == PANNING) {		//平移
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
			begin_x = x;
			begin_y = 500-y;
			SELECTED = 1;
			display();
		}
		else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
			current_x = x;
			current_y = 500 - y;
			SELECTED = 0;
		}
	}
	else if (FLAG == ZOOMING) {		//缩放

	}
	else if (FLAG == ROTATING) {	//旋转

	}
	else if (FLAG == CUT) {		//裁剪

	}
}

void mymotion(int x, int y) {
	current_x = x;
	current_y = 500-y;
	SELECTED = 2;
	cout << "process\n";
	display();
}