#include "shape.h"
#include "point.h"
#include <iostream>

using std::endl;
ostream & operator<<(ostream &output, const Point& p)
{
	output << p.x << " " << p.y;
	return output;
}

ostream & operator<<(ostream &output, const Polygon& v)
{
	for (int i = 0; i < v._vector.size(); i++) {
		output << v._vector[i]<< endl;
	}
	return output;
}
double distance(Point p1, Point p2) {
	double dis = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	return dis;
}

int main2() {
	Point cir_p;
	cir_p.x = 0.3;
	cir_p.y = 0.7;
	circle cir(0.9, cir_p);
	double cir_area=cir.area();
	Point p1, p2;
	p1 = cir_p;
	p2.x = 0.8;
	p2.y = 2.4;
	rectangle rec(p1, p2);
	double rec_area=rec.area();
	Point p3;
	p3.x = 0.5;
	p3.y = 2.4;
	Triangle tri(p1, p2, p3);
	double tri_area=tri.area();
	cout << rec << endl;
	cout << tri << endl;
	return 0;

}