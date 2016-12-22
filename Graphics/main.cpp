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
	glMatrixMode(GL_PROJECTION);	//指定哪一个矩阵为当前矩阵
	glLoadIdentity();	//重置当前指定的矩阵为单位矩阵
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);		//左下角x坐标，右上角x坐标，左下角y坐标，右上角y坐标
	glClearColor(1.0, 1.0, 1.0, 0.0);		//指定清除颜色（黑色），即背景颜色
	glShadeModel(GL_FLAT);				//设置着色模式，采用恒定着色
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
	glutCreateMenu(mymenu);//注册菜单回调函数  
	MenuSettings();
	glutMainLoop();

}


