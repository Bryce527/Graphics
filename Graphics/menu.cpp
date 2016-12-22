#include <iostream>
#include <gl/glut.h>
#include "Common.h"
#include "Mouse.h"
#include "Graphics.h"
using namespace std;

void mymenu(int value) {
	switch (value) {
	case LINE:FLAG = LINE; break;
	case CIRCLE:FLAG = CIRCLE; break;
	case ELLIPSE:FLAG = ELLIPSE; break;
	case POLYGON:FLAG = POLYGON; break;

	case PANNING:FLAG = PANNING; break;
	case ZOOMING:FLAG = ZOOMING; break;
	case ROTATING:FLAG = ROTATING; break;
	case CLEARSCREEN:FLAG = CLEARSCREEN; break;
	case FILLAREA:FLAG = FILLAREA; break;
	case EXIT:FLAG = EXIT; break;

	case RED:COLORFLAG = RED; break;
	case GREEN:COLORFLAG = GREEN; break;
	case BLUE:COLORFLAG = BLUE; break;
	case BLACK:COLORFLAG = BLACK; break;
	case WHITE:COLORFLAG = WHITE; break;
	default:FLAG = -1; break;
	}
	if (FLAG == CLEARSCREEN) {		//清屏
		glClear(GL_COLOR_BUFFER_BIT);
		glutSwapBuffers();
		glFlush();
		graphics.Clear_list();
	}
	else if (FLAG == EXIT) {
		exit(0);
	}
}


void MenuSettings() {
	int BasicDrawingMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("线", LINE);//添加菜单项  
	glutAddMenuEntry("圆", CIRCLE);
	glutAddMenuEntry("椭圆", ELLIPSE);
	glutAddMenuEntry("多边形", POLYGON);

	int FillClearMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("清屏", CLEARSCREEN);
	glutAddMenuEntry("填充区域", FILLAREA);

	int ColorMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("红", RED);
	glutAddMenuEntry("绿", GREEN);
	glutAddMenuEntry("蓝", BLUE);
	glutAddMenuEntry("黑", BLACK);
	glutAddMenuEntry("白", WHITE);

	int pzrMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("平移", PANNING);
	glutAddMenuEntry("旋转", ZOOMING);
	glutAddMenuEntry("缩放", ROTATING);

	int MainMenu = glutCreateMenu(mymenu);
	glutAddSubMenu("基础图形", BasicDrawingMenu);
	glutAddSubMenu("填充/清除", FillClearMenu);
	glutAddSubMenu("交换", pzrMenu);
	glutAddSubMenu("颜色", ColorMenu);
	glutAddMenuEntry("退出", EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//把当前菜单注册到指定的鼠标键
}
