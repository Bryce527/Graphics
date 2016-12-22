#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include "BasicDrawing.h"

class Circle: public BasicDrawing{
public:
	void Draw();
	void Fill();
	void Panning();
	bool is_selected(int x, int y);
private:
	void Cirpot(int x0, int y0, int x, int y);
	void MidPoint_Circle(int x0, int y0, int r);
};

void MidPoint_Circle(int x0, int y0, int r);

#endif