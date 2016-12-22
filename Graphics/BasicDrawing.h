#ifndef __BASICDRAWING_H__
#define __BASICDRAWING_H__
#include <gl/glut.h>
#include "Common.h"

class BasicDrawing {
protected:
	int type;
	int xlist[100], ylist[100];
	int index;
	int lcolor;
	int fcolor;
	bool is_filled;
public:
	//TODO add sth.
	BasicDrawing() {
		index = 0;
		is_filled = false;
	}
	int get_type() {
		return type;
	}
	void set_type(int type) {
		this->type = type;
	}
	void set_is_filled_true() {
		is_filled = true;
	}
	void set_is_filled_false() {
		is_filled = false;
	}
	bool get_is_filled() {
		return is_filled;
	}
	void add_point(int x, int y);
	int get_index() {
		return index;
	}
	void set_lcolor(int color) {
		lcolor = color;
	}
	void set_fcolor(int color) {
		fcolor = color;
	}
	int get_lcolor() {
		return lcolor;
	}
	int get_fcolor() {
		return fcolor;
	}
	void set_color(int color) {
//		glClear(GL_COLOR_BUFFER_BIT);
		switch (color) {
		case 11:glColor3f(1.0, 0.0, 0.0); break;
		case 14:glColor3f(0.0, 0.0, 0.0); break;
		case 13:glColor3f(0.0, 0.0, 1.0); break;
		case 12:glColor3f(1.0, 1.0, 0.0); break;
		case 15:glColor3f(1.0, 1.0, 1.0); break;
		default:glColor3f(0.0, 0.0, 0.0); break;
		}
	}
	virtual void Draw();
	virtual void Fill();
	virtual void Panning();
	virtual void Zooming();
	virtual void Rotating();
	virtual bool is_selected(int x, int y);
	void Set_color();
};

#endif