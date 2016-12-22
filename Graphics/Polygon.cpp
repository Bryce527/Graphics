#include<GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "BasicDrawing.h"
#include "Polygon.h"
#include "Line.h"
using namespace std;

void Polygon::Draw() {
	set_color(lcolor);
	for (int i = 0; i < index-1; i++) {
		LineBresenham(xlist[i],ylist[i], xlist[i+1], ylist[i+1]);
	}
	LineBresenham(xlist[0], ylist[0], xlist[index-1], ylist[index-1]);
	if (is_filled) {
		set_color(fcolor);
		Fill();
	}
}

void Polygon::Fill() {
	int ymin = 0;
	int ymax = 0;
	GetPolygonMinMax(ymin, ymax);

	vector<list<EDGE>> slNet(ymax - ymin + 1);

	InitScanLineNewEdgeTable(slNet, ymin, ymax);

	HorizonEdgeFill();

	ProcessScanLineFill(slNet, ymin, ymax);
	glFlush();

}

void Polygon::InitScanLineNewEdgeTable(vector<list<EDGE>>& slNet, int ymin, int ymax) {
	EDGE e;
	for (int i = 0; i < index; i++) {
		int psx = xlist[i], psy = ylist[i];
		int pex = xlist[(i + 1) % index], pey = ylist[(i + 1) % index];
		int pssx = xlist[(i - 1 + index) % index], pssy = ylist[(i - 1 + index) % index];
		int peex = xlist[(i + 2) % index], peey = ylist[(i + 2) % index];
		if (pey != psy) {	//不处理水平线
			e.dx = (double)(pex - psx) / (double)(pey - psy);
			if (pey > psy) {
				e.xi = psx;
				if (peey >= pey)
					e.ymax = pey - 1;
				else
					e.ymax = pey;
				slNet[psy - ymin].push_front(e);
			}
			else {
				e.xi = pex;
				if (pssy >= psy)
					e.ymax = psy - 1;
				else
					e.ymax = psy;
				slNet[pey - ymin].push_front(e);
			}
		}
	}
}

void Polygon::ProcessScanLineFill(vector<list<EDGE>>& slNet, int ymin, int ymax) {
	list<EDGE> aet;
	for (int y = ymin; y <= ymax; y++) {
		InsertNetListToAet(slNet[y - ymin], aet);

		FillAetScanLine(aet, y);

		RemoveNonActiveEdgeFromAet(aet, y);

		UpdateAndResortAet(aet);
	}
}

void Polygon::HorizonEdgeFill() {

}

bool sort_aet(EDGE& e1, EDGE& e2) {
	if (e1.xi != e2.xi)
		return e1.xi < e2.xi;
	else
		return e1.dx <= e2.dx;
}

void Polygon::InsertNetListToAet(list<EDGE>& sl, list<EDGE>& aet) {
	list<EDGE>::iterator itr = sl.begin();
	for (; itr != sl.end(); itr++) {
		aet.push_back(*itr);
	}
	aet.sort(sort_aet);
}

void Polygon::FillAetScanLine(list<EDGE> aet, int y) {
	list<EDGE>::iterator itr = aet.begin();
	if (aet.size() % 2 == 0)
	for (; itr != aet.end();) {
		int x1 = itr->xi;
		itr++;
		int x2 = itr->xi;
		itr++;
		LineBresenham(x1, y, x2, y);
	}
}

void Polygon::RemoveNonActiveEdgeFromAet(list<EDGE>& aet, int y) {
	list<EDGE>::iterator itr = aet.begin();
	for (; itr != aet.end();) {
		if (itr->ymax == y)
			itr = aet.erase(itr);
		else
			itr++;
	}
	aet.sort(sort_aet);
//	aet.remove_if(std::bind2nd(std::ptr_fun(IsEdgeOutOfActive)), y);
}

/*
void Polygon::UpdateAetEdgeInfo(EDGE& e) {
	e.xi += e.dx;
}*/


void Polygon::UpdateAndResortAet(list<EDGE>& aet) {
//	for_each(aet.begin(), aet.end(), UpdateAetEdgeInfo);
	list<EDGE>::iterator itr = aet.begin();
	for (; itr != aet.end(); itr++) {
		itr->xi += itr->dx;
	}
	aet.sort(sort_aet);
}

void Polygon::GetPolygonMinMax(int &ymin, int &ymax) {
	int tmin = ylist[0], tmax = ylist[0];
	for (int i = 1; i < index; i++) {
		if (ylist[i] < tmin)
			tmin = ylist[i];
		if (ylist[i] > tmax)
			tmax = ylist[i];
	}
	ymin = tmin;
	ymax = tmax;
}

bool Polygon::is_selected(int x, int y) {
	return true;
}