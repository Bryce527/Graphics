#ifndef __POLYGON_H__
#define __POLYGON_H__
#include <list>
#include "BasicDrawing.h"
using namespace std;

struct EDGE {
	double xi;
	double dx;
	int ymax;
};

class Polygon :public BasicDrawing {
public:
	void Draw();
	void Fill();
	bool is_selected(int x, int y);
private:
	void GetPolygonMinMax(int &ymin, int &ymax);
	void InitScanLineNewEdgeTable(vector<list<EDGE>>& slNet, int ymin, int ymax);
	void HorizonEdgeFill();
	void ProcessScanLineFill(vector<list<EDGE>>& slNet, int ymin, int ymax);
	void InsertNetListToAet(list<EDGE>& sl, list<EDGE>& aet);
	void FillAetScanLine(list<EDGE> aet, int y);
	void RemoveNonActiveEdgeFromAet(list<EDGE>& aet, int y);
	void UpdateAndResortAet(list<EDGE>& aet);
//	void UpdateAetEdgeInfo(EDGE& e);
};
#endif