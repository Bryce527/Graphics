#include <iostream>
#include <gl/glut.h>
#include "BasicDrawing.h"
#include "Common.h"
using namespace std;


void BasicDrawing::add_point(int x, int y) {
	xlist[index] = x;
	ylist[index] = y;
	index++;
}

void BasicDrawing::Draw() {
	printf("not here");
}

void BasicDrawing::Fill() {
}

void BasicDrawing::Set_color() {
	switch (fcolor) {
	case RED:glColor3f(1.0, 0.0, 0.0); break;
	case GREEN:glColor3f(0.0, 1.0, 0.0); break;
	case BLUE:glColor3f(0.0, 0.0, 1.0); break;
	case BLACK:glColor3f(0.0, 0.0, 0.0); break;
	case WHITE:glColor3f(1.0, 1.0, 1.0); break;
	}
}

bool BasicDrawing::is_selected(int x, int y) {
	printf("not here\n");
	return true;
}


void BasicDrawing::Panning() {
}

void BasicDrawing::Rotating() {

}

void BasicDrawing::Zooming() {

}