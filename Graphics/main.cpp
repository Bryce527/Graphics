#include<stdio.h>
#include<GL/glut.h>
#include <vector>
#include "BasicDrawing.h"
#include "Mouse.h"
#include "KeyBoard.h"
#include "menu.h"
#include "Common.h"
#include "Display.h"
using namespace std;

void init() {
	glMatrixMode(GL_PROJECTION);	//ָ����һ������Ϊ��ǰ����
	glLoadIdentity();	//���õ�ǰָ���ľ���Ϊ��λ����
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);		//���½�x���꣬���Ͻ�x���꣬���½�y���꣬���Ͻ�y����
	glClearColor(1.0, 1.0, 1.0, 0.0);		//ָ�������ɫ����ɫ������������ɫ
	glShadeModel(GL_FLAT);				//������ɫģʽ�����ú㶨��ɫ
}


int main(int argc, char**argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My OpenGL");
	init();
	glutMouseFunc(mymouse);
	glutMotionFunc(mymotion);
	glutKeyboardFunc(mykey);
	glutDisplayFunc(display);
	glutCreateMenu(mymenu);//ע��˵��ص�����  
	MenuSettings();
	glutMainLoop();

}


