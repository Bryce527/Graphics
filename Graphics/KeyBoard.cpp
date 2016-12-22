#include<GL/glut.h>
#include<iostream>
#include <cmath>
#include "BasicDrawing.h"
#include "Common.h"

void mykey(unsigned char key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		printf("f1\n"); break;
	case 27:
		exit(0); break;
	}
}