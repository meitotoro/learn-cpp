#pragma once
#include "point.h"
#include "shape.h"
#include <vector>


const double pi = 3.14159265358979323846;

double circle::area() {
	double s = pi * pow(_radius, 2);
	return s;
}
circle::circle(double radius, Point p) :_radius(radius), _p(p)
{
}


rectangle::rectangle(Point p1, Point p2) : Polygon({ p1,p2 }), plt(_vector[0]), prb(_vector[1])
{
}

double rectangle::area() {
	double lon = abs(plt.x - prb.x);
	double wid = abs(plt.y - prb.y);
	double s = lon * wid;
	return s;
}

Triangle::Triangle(Point p1, Point p2, Point p3) :Polygon({ p1,p2,p3 })
{
}

double Triangle::area() {//假设这三个参数是逆时针排序
	Point p1 = _vector[0];
	Point p2 = _vector[1];
	Point p3 = _vector[2];
	double s = 0.5 * (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p1.x*p3.y - p2.x*p1.y - p3.x*p2.y);
	return s;
}

Polygon::Polygon(vector<Point> v) :_vector(v)
{
}
