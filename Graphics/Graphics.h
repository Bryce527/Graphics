#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include <vector>
#include "BasicDrawing.h"
using namespace std;

class Graphics {
private:
	vector<BasicDrawing*> graphics_list;
public:
	Graphics() {
		graphics_list.clear();
	}
	void set_color(int color);

	void Draw_list_loop();

	void Clear_list();

	void Add_to_list(BasicDrawing* bd);

	void Delete_element();

	void print();

	void fill_by_xy(int x, int y);
	void panning_by_xy(int x, int y);
};

extern Graphics graphics;
extern BasicDrawing* current_bd;

#endif