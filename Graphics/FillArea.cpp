#include <iostream>
#include <gl/glut.h>
#include <stack>
#include <list>
#include <vector>
using namespace std;


/*void ScanLineSeedFill(int x, int y, int new_color, int boundary_color)

{
	std::stack<Point> stk;
	stk.push(Point(x, y)); //��1�������ӵ���վ

	while (!stk.empty())
	{

		Point seed = stk.top(); //��2����ȡ��ǰ���ӵ�

		stk.pop();

		

		//��3�������������

		int count = FillLineRight(seed.x, seed.y, new_color, boundary_color);//��'cf?��'d3?��'cc?��'b3?

		int xRight = seed.x + count - 1;

		count = FillLineLeft(seed.x - 1, seed.y, new_color, boundary_color);//��'cf?��'d7?��'cc?��'b3?

		int xLeft = seed.x - count;


		//��4����������������ɨ����

		SearchLineNewSeed(stk, xLeft, xRight, seed.y - 1, new_color, boundary_color);

		SearchLineNewSeed(stk, xLeft, xRight, seed.y + 1, new_color, boundary_color);

	}

}


void SearchLineNewSeed(std::stack<Point>& stk, int xLeft, int xRight, int y, int new_color, int boundary_color) {

	int xt = xLeft;

	bool findNewSeed = false;
	
	while (xt <= xRight)

	{
		findNewSeed = false;

		while (IsPixelValid(xt, y, new_color, boundary_color) && (xt < xRight))

		{

			findNewSeed = true;

			xt++;

		}

		if (findNewSeed)
		{

			if (IsPixelValid(xt, y, new_color, boundary_color) && (xt == xRight))

				stk.push(Point(xt, y));

			else

				stk.push(Point(xt - 1, y));

			}
		//���������ڲ�����Ч�㣨���������Ҷ����ϰ���������

		int xspan = SkipInvalidInLine(xt, y, xRight, new_color, boundary_color);

		xt += (xspan == 0) ? 1 : xspan;

		//�����������,���˳�while(x<=xright)ѭ��

	}

}*/

/*
typedef struct tagEDGE
{

	double xi;

	double dx;

	int ymax;

}EDGE;

void ScanLinePolygonFill(const Polygon& py, int color)
{

//	assert(py.IsValid());

	int ymin = 0;

	int ymax = 0;

	GetPolygonMinMax(py, ymin, ymax);

	std::vector< std::list<EDGE> > slNet(ymax - ymin + 1);

	InitScanLineNewEdgeTable(slNet, py, ymin, ymax);

	//PrintNewEdgeTable(slNet);

	HorizonEdgeFill(py, color); //ˮƽ��ֱ�ӻ������

	ProcessScanLineFill(slNet, ymin, ymax, color);

}

void InitScanLineNewEdgeTable(std::vector< std::list<EDGE> >& slNet,const Polygon& py, int ymin, int ymax)
{

	EDGE e;

	for (int i = 0; i < py.GetPolyCount(); i++)
	{

		const Point& ps = py.pts[i];

		const Point& pe = py.pts[(i + 1) % py.GetPolyCount()];

		const Point& pss = py.pts[(i - 1 + py.GetPolyCount()) % py.GetPolyCount()];

		const Point& pee = py.pts[(i + 2) % py.GetPolyCount()];

		if (pe.y != ps.y) //������ˮƽ��

		{

			e.dx = double(pe.x - ps.x) / double(pe.y - ps.y);

			if (pe.y > ps.y)
			{

				e.xi = ps.x;

				if (pee.y >= pe.y)

					e.ymax = pe.y - 1;

				else

					e.ymax = pe.y;

				slNet[ps.y - ymin].push_front(e);

				}

			else

				{

				e.xi = pe.x;

				if (pss.y >= ps.y)

					e.ymax = ps.y - 1;

				else

					e.ymax = ps.y;

				slNet[pe.y - ymin].push_front(e);

				}

			}

		}

}


void ProcessScanLineFill(std::vector< std::list<EDGE> >& slNet,int ymin, int ymax, int color)

{

	std::list<EDGE> aet;

	for (int y = ymin; y <= ymax; y++)

	{

		InsertNetListToAet(slNet[y - ymin], aet);

		475         FillAetScanLine(aet, y, color);

		RemoveNonActiveEdgeFromAet(aet, y);

		UpdateAndResortAet(aet);

	}

}

bool IsEdgeOutOfActive(EDGE e, int y)
{

	return (e.ymax == y);

}

void RemoveNonActiveEdgeFromAet(std::list<EDGE>& aet, int y)
{

	aet.remove_if(std::bind2nd(std::ptr_fun(IsEdgeOutOfActive), y));

}

void UpdateAetEdgeInfo(EDGE& e) {

	e.xi += e.dx;

}

bool EdgeXiComparator(EDGE& e1, EDGE& e2) {

	return (e1.xi <= e2.xi);
}

void UpdateAndResortAet(std::list<EDGE>& aet)
{

	for_each(aet.begin(), aet.end(), UpdateAetEdgeInfo);

	aet.sort(EdgeXiComparator);

}*/