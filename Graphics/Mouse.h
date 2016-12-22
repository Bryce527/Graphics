#ifndef __MOUSE_H__
#define __MOUSE_H__

void mymouse(int button, int state, int x, int y);
void mymotion(int x, int y);

extern int begin_x, begin_y;
extern int current_x, current_y;
extern int list_index;
extern int Xlist[100], Ylist[100];
extern int FLAG;
extern int COLORFLAG;
extern int SELECTED;

#endif