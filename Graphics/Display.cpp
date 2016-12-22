#include <gl/glut.h>
#include <iostream>
#include "Graphics.h"
#include "Mouse.h"
#include "Common.h"
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Polygon.h"
using namespace std;

void display() {
//	printf("1111111\n");
	glClear(GL_COLOR_BUFFER_BIT);
	graphics.set_color(COLORFLAG);

	graphics.Draw_list_loop();
	switch (FLAG) {
	case LINE:LineBresenham(begin_x, begin_y, current_x, current_y); break;
	case CIRCLE:MidPoint_Circle(begin_x, begin_y, sqrt((current_x - begin_x)*(current_x - begin_x) + (current_y - begin_y)*(current_y - begin_y))); break;
	case ELLIPSE:MidPoint_Ellipse(begin_x, begin_y, abs(current_x-begin_x), abs(current_y-begin_y)); break;
	case POLYGON:break;
	case FILLAREA:graphics.fill_by_xy(begin_x, begin_y); break;
	case PANNING:graphics.panning_by_xy(begin_x, begin_y); break;
	default:break;
	}
	glFlush();
}