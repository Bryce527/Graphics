#ifndef __LINE_H__
#define __LINE_H__
#include "BasicDrawing.h"

class Line :public BasicDrawing {
public:
	void Draw();
	void Fill();
	void Panning();
	bool is_selected(int x, int y);
private:
	void LineBresenham(int xBegin, int yBegin, int xEnd, int yEnd);
};

void LineBresenham(int xBegin, int yBegin, int xEnd, int yEnd);

#endif