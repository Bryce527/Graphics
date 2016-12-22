#ifndef __ELLIPSE_H__
#define __ELLIPSE_H__
#include <iostream>
#include "BasicDrawing.h"
using namespace std;

class Ellipse : public BasicDrawing {
public:
	void Draw();
	void Fill();
	void Panning();
	bool is_selected(int x, int y);
private:
	void Cirpot(int x0, int y0, int x, int y);
	void MidPoint_Ellipse(int x0, int y0, int rx, int ry);
};

void MidPoint_Ellipse(int x0, int y0, int rx, int ry);

#endif