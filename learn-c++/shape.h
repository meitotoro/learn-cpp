#pragma once
#include "point.h"
#include <vector>

class shape {
public:
	virtual double area() = 0;
};
class circle :public shape {
private:
	Point _p;
	double _radius;
public:
	double area();
	circle(double radius, Point p) ;

};
class Polygon :public shape {
protected:
	vector<Point> _vector;
public:
	Polygon(vector<Point> v);
	friend ostream & operator<<(ostream &output, const Polygon& v);

};
class rectangle :public Polygon {
private:
	Point &plt;
	Point &prb;
public:
	rectangle(Point p1, Point p2);
	double area();
};
class Triangle : public Polygon {
private:
public:
	Triangle(Point p1, Point p2, Point p3);
	double area();
};