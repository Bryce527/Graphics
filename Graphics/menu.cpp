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
	if (FLAG == CLEARSCREEN) {		//����
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
	glutAddMenuEntry("��", LINE);//��Ӳ˵���  
	glutAddMenuEntry("Բ", CIRCLE);
	glutAddMenuEntry("��Բ", ELLIPSE);
	glutAddMenuEntry("�����", POLYGON);

	int FillClearMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("����", CLEARSCREEN);
	glutAddMenuEntry("�������", FILLAREA);

	int ColorMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("��", RED);
	glutAddMenuEntry("��", GREEN);
	glutAddMenuEntry("��", BLUE);
	glutAddMenuEntry("��", BLACK);
	glutAddMenuEntry("��", WHITE);

	int pzrMenu = glutCreateMenu(mymenu);
	glutAddMenuEntry("ƽ��", PANNING);
	glutAddMenuEntry("��ת", ZOOMING);
	glutAddMenuEntry("����", ROTATING);

	int MainMenu = glutCreateMenu(mymenu);
	glutAddSubMenu("����ͼ��", BasicDrawingMenu);
	glutAddSubMenu("���/���", FillClearMenu);
	glutAddSubMenu("����", pzrMenu);
	glutAddSubMenu("��ɫ", ColorMenu);
	glutAddMenuEntry("�˳�", EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//�ѵ�ǰ�˵�ע�ᵽָ��������
}
