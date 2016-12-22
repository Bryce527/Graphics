#include <iostream>
#include <vector>
#include "BasicDrawing.h"
#include "Graphics.h"
#include "Mouse.h"
using namespace std;

//全局变量
Graphics graphics;
BasicDrawing* current_bd = NULL;

void Graphics::Draw_list_loop() {
	vector<BasicDrawing*>::iterator itr = graphics_list.begin();
	for (; itr != graphics_list.end(); itr++) {
		(*itr)->Draw();
	}
}

void Graphics::set_color(int color) {
//	glClear(GL_COLOR_BUFFER_BIT);
	switch (color) {
	case 11:glColor3f(1.0, 0.0, 0.0); break;
	case 14:glColor3f(0.0, 0.0, 0.0); break;
	case 13:glColor3f(0.0, 0.0, 1.0); break;
	case 12:glColor3f(1.0, 1.0, 0.0); break;
	case 15:glColor3f(1.0, 1.0, 1.0); break;
	default:glColor3f(0.0, 0.0, 0.0); break;
	}
}

void Graphics::print() {
	vector<BasicDrawing*>::iterator itr = graphics_list.begin();
	printf("---------\n");
	for (; itr != graphics_list.end(); itr++) {
		printf("%d ", (*itr)->get_index());
	}
	printf("---------\n");
}
void Graphics::Add_to_list(BasicDrawing* bd) {
	graphics_list.push_back(bd);
}

void Graphics::Clear_list() {
	graphics_list.clear();
}

void Graphics::fill_by_xy(int x, int y) {
	vector<BasicDrawing*>::iterator itr = graphics_list.begin();
	for (; itr != graphics_list.end(); itr++) {
		printf("injudge\n");
		if ((*itr)->is_selected(x, y)) {
			printf("judge succeed\n");
			(*itr)->set_is_filled_true();
			(*itr)->set_fcolor(COLORFLAG);
			(*itr)->Fill();
//			glFlush();
			return;
		}
	}
}


void Graphics::panning_by_xy(int x, int y) {
	if (SELECTED == 1) {
		vector<BasicDrawing*>::iterator itr = graphics_list.begin();
		for (; itr != graphics_list.end(); itr++) {
			printf("injudge\n");
			if ((*itr)->is_selected(x, y)) {
				printf("judge succeed\n");
				current_bd = *itr;
				return;
			}
		}
		current_bd = NULL;
	}
	else if (SELECTED == 2) {
		if (current_bd != NULL)
			current_bd->Panning();
	}

}